#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"


SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

//Initilize the Digital pins for the push buttons for the songs
const int buttonPin2 = 2;
const int buttonPin3 = 3;
const int buttonPin4 = 4;
const int buttonPin5 = 5;

// Default push button status
int button2State = 0;         
int button3State = 0;
int button4State = 0;
int button5State = 0;

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200); //Initilize Serial Monitor for status and debugging
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true){
      delay(0); // Code to compatible with ESP8266 watch dog.
    }
  }
  Serial.println(F("DFPlayer Mini online."));

  //Set push button pin to an INPUT
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);
  pinMode(buttonPin5, INPUT);
  
  myDFPlayer.volume(15);  //Set volume value. From 0 to 30

}

void loop()
{  

  // read the state of the pushbutton value:
  button2State = digitalRead(buttonPin2);
  button3State = digitalRead(buttonPin3);
  button4State = digitalRead(buttonPin4);
  button5State = digitalRead(buttonPin5);
  
  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (button2State == HIGH) {
    play(1);
  }
  if (button3State == HIGH) {
    play(2);
  }
  if (button4State == HIGH) {
    play(3);
  }
  if (button5State == HIGH) {
    play(4);
  }
  

}

//Play Function passes what song to play and then sets a 10 second delay so the buttons are deactivated.  Prevents double press by toddler.
//See ReadME.md for list of songs
void play(int s)
{
    
    myDFPlayer.play(s);  //Play the first mp3
    delay(10000); //Adjust delay as needed
  

}
