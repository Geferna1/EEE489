//ALL code will be in this file, when testing one part, comment out the rest of the code or copy the section and paste in a seperate file. Please leave comments whenever the code is updated.

//PWM Code for DC Motor Control
int pwm = 12; // assigns pin 12 to variable pwm
int pot = A0; // assigns analog input A0 to variable pot
int t1 = 0;   // declares variable t1
int t2 = 0;   // declares variable t2
void setup()  // setup loop
{
  pinMode(pwm, OUTPUT); // declares pin 12 as output
  pinMode(pot, INPUT);  // declares pin A0 as input
}
void loop()
{
  t2= analogRead(pot); // reads the voltage at A0 and saves in t2
  t1= 1000-t2;         // subtracts t2 from 1000 ans saves the result in t1
  digitalWrite(pwm, HIGH); // sets pin 12 HIGH
  delayMicroseconds(t1);   // waits for t1 uS (high time)
  digitalWrite(pwm, LOW);  // sets pin 12 LOW
  delayMicroseconds(t2);   // waits for t2 uS (low time)
}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//LED code
const int ledPin = 9;      // the pin that the LED is attached to

void setup() {

  // initialize the serial communication:

  Serial.begin(9600);

  // initialize the ledPin as an output:

  pinMode(ledPin, OUTPUT);
}

void loop() {

  byte brightness;

  // check if data has been sent from the computer:

  if (Serial.available()) {

    // read the most recent byte (which will be from 0 to 255):

    brightness = Serial.read();

    // set the brightness of the LED:

    analogWrite(ledPin, brightness);

  }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//BATTERY LEVEL Code
int value = 0;
float voltage;
float perc;

void setup(){
  Serial.begin(9600);
}

void loop(){
  value = analogRead(A0);
  voltage = value * 5.0/1023;
  perc = map(voltage, 3.6, 4.2, 0, 100);
  Serial.print("Voltage= ");
  Serial.println(voltage);
  Serial.print("Battery level= ");
  Serial.print(perc);
  Serial.println(" %");
  delay(500);
}

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
