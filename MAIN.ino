//LIBRARY
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

//Set LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//PIN
const int LIGHT1 = 11;
const int LIGHT2 = 12;
const int LIGHT3 = 13;
const int HOURS_ON = 12;
const int PUMP = 10;

//SETTINGS
int AMOUNT_OF_WATER = (120000);
int MSON = HOURS_ON * 3.6 * pow(10, 6);
int MSOFF = 24 * pow(10, 6) - MSON;

//VARIABELS, moet nog: tijd, licht-intesiteit, hoogte plant.
float Temperature = 0;

//Configures the arduino to the correct pins and starts the machine
void setup() {
  //LIGHTS:
  pinMode(LIGHT1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);
  pinMode(LIGHT3, OUTPUT);

  //PUMP
  pinMode(PUMP, OUTPUT);

  //LCD
  lcd.begin(); //Initialise the lcd
  lcd.backlight(); //turn on the backlight and print a message
  lcd.setCursor(0,0); //set cursor
  lcd.print("STARTING...") //display "STARTING..." as test
}
//MAIN
void loop() {
  lightsOn();
  delay(43200000); //wait 12 hours 
  lightsOff()
  delay(43200000); //wait 12 hours

}

//FUNCTIONS
//Turn on the lights
void lightsOn() {
  digitalWrite(LIGHT1, HIGH);
  digitalWrite(LIGHT2, HIGH);
  digitalWrite(LIGHT3, HIGH);
}

//Turn the lights off
void lightsOff() {
  digitalWrite(LIGHT1, LOW);
  digitalWrite(LIGHT2, LOW);
  digitalWrite(LIGHT3, LOW);
}

//Pumps water during a set amount of time (AMOUNT_OF_WATER) in ms
void pumpCycle() {
  digitalWrite(PUMP,HIGH);
  delay(AMOUNT_OF_WATER);
  digitalWrite(PUMP,LOW);
  delay(3000);
}

//Sends given input to the lcd to be displayed
void lcdInput() {
  //kan info geven, moeten nog beslissen wat
}











