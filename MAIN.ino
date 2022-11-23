//PINS
const int LIGHT1 = 11;
const int LIGHT2 = 12;
const int LIGHT3 = 13;
const int HOURS_ON = 1;
const int PUMP = 10;

//SETTINGS
int AMOUNT_OF_WATER = (3000);
int MSON = HOURS_ON * 3.6 * pow(10, 6);
int MSOFF = 24 * pow(10, 6) - MSON;

void setup() {
  //LIGHTS:
  pinMode(LIGHT1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);
  pinMode(LIGHT3, OUTPUT);
  //PUMP
  pinMode(PUMP, OUTPUT);
  

}
//Intensity PWM
int PWM = 0.50 * 255;
}

void loop() {
  lightsOn()



}
void lightsOn() {
  //Zet lampen AAN
  digitalWrite(LIGHT1, HIGH);
  digitalWrite(LIGHT2, HIGH);
  digitalWrite(LIGHT3, HIGH);
  delay(MSON);
}

void lightsOff() {
  //Zet lampen UIT
  digitalWrite(LIGHT1, LOW);
  digitalWrite(LIGHT2, LOW;
  digitalWrite(LIGHT3, LOW);
  delay(MSOFF);
}

void pumpCycle() {
  digitalWrite(PUMP,HIGH);
  delay(AMOUNT_OF_WATER);
  digitalWrite(PUMP,LOW);
}

void 





