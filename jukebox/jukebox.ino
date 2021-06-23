

#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>
#include <SPI.h>

TMRpcm tmrpcm;

void setup()
{
tmrpcm.speakerPin=9;
Serial.begin(9600);
if(!SD.begin(SD_ChipSelectPin))
{
  Serial.println("SD fail");
  return;
}
tmrpcm.setVolume(6);
tmrpcm.play((char*)"song1.wav");

}

void loop() {
  // put your main code here, to run repeatedly:
  play();

}

void play (void)
{

  tmrpcm.play((char*)"song1.wav");
  delay(10000);
}
