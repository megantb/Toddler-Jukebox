#include <SD.h> // need to include the SD library
#define SD_ChipSelectPin 4 //connect pin 4 of arduino to cs pin of sd card
#include <TMRpcm.h> //Arduino library for asynchronous playback of PCM/WAV files
#include <SPI.h> //  need to include the SPI library

TMRpcm tmrpcm; // create an object for use in this sketch
int songselect = 0
int song1=5;  //song1 button pin
int song2=6;  //song2 button pin
int song3=7;  //song3 button pin
int song4=8;  //song4 button pin
int song5=9;  //song5 buttong pin

void setup()
{ 
 pinMode(song1,INPUT_PULLUP);
 pinMode(song2,INPUT_PULLUP);
 pinMode(song3,INPUT_PULLUP);
 pinMode(song4,INPUT_PULLUP);
 pinMode(song5,INPUT_PULLUP);
 
 tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc
 Serial.begin(9600);
 if (!SD.begin(SD_ChipSelectPin)) // returns 1 if the card is present
 {
  Serial.println("SD fail");
  return;
 }

 tmrpcm.setVolume(5); //
                      
}


void loop()
{  
  while(digitalRead(song1)==0 || digitalRead(song2)==0 || digitalRead(song3)==0|| digitalRead(song4)==0|| digitalRead(song5)==0)
  {
    if(digitalRead(song1)==0)
    {
      songselect = 1;
      while(digitalRead(song1)==0);
      delay(200);
      song();
      
    }
    else if(digitalRead(song2)==0)
    {
      songselect = 2;
      while(digitalRead(song2)==0);
      delay(200);
      song();
    }
    else if(digitalRead(song3)==0)
    {
      songselect = 3;
      while(digitalRead(song3)==0);
      delay(200);
      song();
    }
    else if(digitalRead(song4)==0)
    {
      songselect = 4;
      while(digitalRead(song4)==0);
      delay(200);
      song();
    }
    else if(digitalRead(song5)==0)
    {
      songselect = 5;
      while(digitalRead(song5)==0);
      delay(200);
      song();
    }
  }
}

void song (void)
{
  if(songselect==1)
  {
    tmrpcm.play("song1.wav");  
  }
  else if(songselect==2)
  {
    tmrpcm.play("song2.wav");  
  }
  else if(songselect==3)
  {
    tmrpcm.play("song3.wav");  
  }
  else if(songselect==4)
  {
    tmrpcm.play("song4.wav");  
  }
  else if(songselect==5)
  {
    tmrpcm.play("song5.wav");  
  }
}
