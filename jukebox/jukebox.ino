

#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
#include <SPI.h>

TMRpcm tmrpcm;
const int buttonPin = 2;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup()
{
pinMode(buttonPin, INPUT);

tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.quality(1);
tmrpcm.setVolume(6);


}

void loop() {
  // put your main code here, to run repeatedly:

  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    play();
  }

}

void play (void)
{

  tmrpcm.play((char*)"Daniel.wav");
  delay(150000);
}
