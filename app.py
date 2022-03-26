import serial
import time
import RPi.GPIO as GPIO
from flask import Flask, render_template, request
app = Flask(__name__)

GPIO.setmode(GPIO.BCM)

if __name__ == 'main':
    ser = serial.Serial('/dev/ttyACM0',9600, timeout=1)
    ser.flush()

pins = {
   15 : {'name' : 'LIGHTS', 'state' : GPIO.LOW},
   14 : {'name' : 'TREE','state' : GPIO.LOW},
   9 : {'name' : 'JINGLE BELLS LIGHTS', 'state' : GPIO.LOW}
   }

for pin in pins:
   GPIO.setup(pin, GPIO.OUT)
   GPIO.output(pin, GPIO.LOW)

@app.route("/")
def main():
   for pin in pins:
      pins[pin]['state'] = GPIO.input(pin)
   templateData = {
      'pins' : pins
      }
   return render_template('main.html', **templateData)

@app.route("/<changePin>/<action>")
def action(changePin, action):
   changePin = int(changePin)
   deviceName = pins[changePin]['name']
   if action == "on":
      if changePin == 9:
        GPIO.output(changePin, GPIO.LOW)
        ser = serial.Serial('/dev/ttyACM0',9600, timeout=1)
        ser.write(b"RESET NOW")
      if changePin == 14:
        GPIO.output(changePin, GPIO.HIGH)
      if changePin == 15:
        GPIO.output(changePin, GPIO.HIGH)
      message = "Turned " + deviceName + " on."
   if action == "off":
      GPIO.output(changePin, GPIO.LOW)
      message = "Turned " + deviceName + " off."

   for pin in pins:
      pins[pin]['state'] = GPIO.input(pin)

   templateData = {
      'pins' : pins
   }

   return render_template('main.html', **templateData)

if __name__ == "__main__":
   app.run(host='raspberry pi IP here', port=80, debug=True)
