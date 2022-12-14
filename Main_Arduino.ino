//This Program is made for a vertical farming machine that we build during our
//engineering project at the University of Ghent

//LIBRARY
#include <Wire.h>
#include <LiquidCrystal_I2C.h> //Library for LCD
#include <TimeLib.h>
#include <DS1307RTC.h>

//PIN_NUMBERS
const int LIGHT1 = 11; //PIN OF LIGHT 1
const int LIGHT2 = 12; //PIN OF LIGHT 2
const int LIGHT3 = 13; //PIN OF LIGHT 3
const int PUMP = 10; //PIN OF PUMP
const int MOISTURE_ANALOGIC_IN = A0; // Arduino's analogic pin

//SETTINGS
const int HOURS_ON = 12; 
const int AMOUNT_OF_WATER = (10000); //Time of pumping water
const int BOARD_RESOLUTION = 1024; // The analogic board resolution
const float OPERATIONAL_VOLTAGE = 5.0; // The default Arduino voltage
const float MAX_SENSOR_VOLTAGE = 3.0; // The maximum voltage that the sensor can output
const float SENSOR_READ_RATIO = OPERATIONAL_VOLTAGE / MAX_SENSOR_VOLTAGE; // The ratio betwent the two voltages

LiquidCrystal_I2C lcd(0x27, 16, 2); //Set LCD address to 0x27 for a 16 chars and 2 line display

const int needWaterValue = 800; //Value that indicates when the soil is just right and if it needs water

//VARIABELS, moet nog: tijd, licht-intesiteit, hoogte plant.
float Temperature = 0; //temperature box

const int *On[13] = {9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21};

tmElements_t tm;

//Configures the arduino to the correct pins and starts the machine
void setup() {
  //LIGHTS:
  pinMode(LIGHT1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);
  pinMode(LIGHT3, OUTPUT);

  //PUMP
  pinMode(PUMP, OUTPUT);

  //MOISTURESENSOR
  Serial.begin(9600); // Serial Port setup

  //LCD
  lcd.begin();              //Initialise the lcd
  lcd.backlight();          //turn on the backlight and print a message
  lcd.setCursor(0, 0);      //set cursor
  lcd.println("STARTING...");  //display "STARTING..." as test
  //Test
  Serial.begin(9600);
  lcd.clear();

}
//MAIN
void loop() {
lampsOnOrOff();
addWater();
lcdUpdate();
delay(2000);
}
//FUNCTIONS

//Lights

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

//LCD

//Sends given input to the lcd to be displayed
void lcdUpdate() {
  lcd.setCursor(0, 0);
  lcd.println("vochtigheid:");
  lcd.setCursor(0, 1);
  lcd.println(int(readMoistureLevel()));
}

//MoistureSensor

//Reads the moisture data given by the sensor and returns it
int readMoistureLevel() {
  int moistureAnalogicVal = analogRead(MOISTURE_ANALOGIC_IN) * SENSOR_READ_RATIO; // Read the analogic data and convert it to [0, 1023] range
  return moistureAnalogicVal;
}

//Pump

//Pumps water during a set amount of time (AMOUNT_OF_WATER) in ms
void pumpCycle() {
  digitalWrite(PUMP, HIGH);
  delay(AMOUNT_OF_WATER);
  digitalWrite(PUMP, LOW);
  delay(3000);
}

//Check moisturelevel and decide if water needs to be added
void addWater() {
  int errorCheck = 0;
  int moistureLevel = readMoistureLevel();
  while (moistureLevel >= needWaterValue) {
    if (errorCheck <= 5) {
      pumpCycle();
      delay(60000);
      moistureLevel = readMoistureLevel();
      errorCheck += 1;    
      }
    else
     return;
  }
  }

tmElements_t time() {
  RTC.read(tm);
  return tm;
}


//Function that checks the time and decides if lamps should be ON or OFF
 void lampsOnOrOff () {
  RTC.read(tm);
  int tm_correct = int(time().Hour);
  int x;
  Serial.print(int(tm_correct));
  for (int x = 0; x<13; x++){  
    if (int(On[x]) == tm_correct) {
      lightsOn();
      return;}
  }
  return;
  }



void logger() {

}
//functions that helps to determine errors
void error(int errorCode) {
  if (errorCode == 100) {
    lcd.println();
  }
  
}


