/*
  DESCRIPTION
  Simple example for creating a walkie talkie by sending audio
  using the nRF24L01 RF transceiver module.


  DISCLAIMER
  This code is in the public domain. Please feel free to modify,
  use, etc however you see fit. But, please give reference to
  original authors as a courtesy to Open Source developers.

  Modified example from RF24 Audio Library by TMRh20. Comments
  from TMRh20 below.
*/

/* RF24 Audio Library TMRh20 2014

  This sketch is intended to demonstrate the basic functionality of the audio library.

  Requirements:
  2 Arduinos (Uno,Nano,Mega, etc supported)
  2 NRF24LO1 Radio Modules
  1 or more input devices (microphone, ipod, etc)
  1 or more output devices (speaker, amplifier, etc)

  Setup:
  1. Change the CE,CS pins below to match your chosen pins (I use 7,8 on 328 boards, and 48,49 on Mega boards)
  2. Upload this sketch to two or more devices
  3. Default Pin Selections:
  Speaker: pins 9,10 on UNO, Nano, pins 11,12 on Mega 2560
  Input/Microphone: Analog pin A0 on all boards

*/


#include <RF24.h>
#include <SPI.h>
#include "printf.h" // General includes for radio and audio lib
#include <RF24Audio.h>


RF24 radio(7, 8); // Set radio up using pins 7 (CE) 8 (CS)
RF24Audio rfAudio(radio, 0); // Set up the audio using the radio, and set to radio number 0

int talkButton = 3;

void setup() {
  Serial.begin(115200);

  printf_begin();
  radio.begin();
  radio.printDetails();
  rfAudio.begin();

  pinMode(talkButton, INPUT);

  //sets interrupt to check for button talk abutton press
  attachInterrupt(digitalPinToInterrupt(talkButton), talk, CHANGE);

  //sets the default state for each module to recevie
  rfAudio.receive();

}


//void talk()
//Called in response to interrupt. Checks the state of the button.
//If the button is pressed (and held) enters transmit mode to send
//audio. If button is release, enters receive mode to listen.
void talk()
{

  if (digitalRead(talkButton)) {
    rfAudio.transmit();
  }
  else {
    rfAudio.receive();
  }
}


void loop()
{
}
