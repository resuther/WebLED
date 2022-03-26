// Jingle Bells + Raspberry Pi BUS Restart
#include "pitches.h"

int melody[] = {
  NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4,
  NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_FS4,
  NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_B4, NOTE_D4,
  NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_D4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4,
  NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5,
  NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_B4, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_B4, NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_D5,
  NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_B4, NOTE_D5, NOTE_G4, NOTE_A4, NOTE_B4,
  NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_B4, NOTE_B4, NOTE_B4, NOTE_B4,
  NOTE_D5, NOTE_D5, NOTE_C5, NOTE_A4, NOTE_G4 };

int noteDurations[] = {

  8, 8, 8, 8, 3, 16, 16,
  8, 8, 8, 8, 2,
  8, 8, 8, 8, 2, 
  8, 8, 8, 8, 3, 8,
  8, 8, 8, 8, 3, 16, 16,
  8, 8, 8, 8, 3, 8,
  8, 8, 8, 8, 8, 8, 8, 8,
  8, 8, 8, 8, 2,
  8, 8, 4, 8, 8, 4,
  8, 8, 6, 16, 2,
  8, 8, 6, 16, 8, 8, 8, 16, 16,
  8, 8, 8, 8, 4, 4,
  8, 8, 4, 8, 8, 4, 8, 8, 6, 16, 2,
  8, 8, 6, 16, 8, 8, 8, 16, 16,
  8, 8, 8, 8, 2 };

void setup() {
    pinMode(3,OUTPUT);
    pinMode(6,OUTPUT);
    pinMode(9,OUTPUT);
    pinMode(11,OUTPUT);
    digitalWrite(3, LOW);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
    digitalWrite(11, LOW);
  for (int thisNote = 0; thisNote < 100; thisNote++) {

    int noteDuration = 1800/noteDurations[thisNote];
    // I found that by lengthening the noteDuration,
    // I was able to "slow" the song down.
    tone(7, melody[thisNote],noteDuration);
    LEDon();

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(7);
    LEDoff();
  }
}

void loop() {

}

int currentLEDpin=3;
void LEDon()
{
    digitalWrite(currentLEDpin, HIGH);
}

void LEDoff()
{
    digitalWrite(currentLEDpin, LOW);
    if (currentLEDpin==3) currentLEDpin=9;
    else if (currentLEDpin==3) currentLEDpin=9;
    else if (currentLEDpin==9) currentLEDpin=3;
    else currentLEDpin=9;
}

void software_Reset()
{
asm volatile ("  jmp 0");  
}
