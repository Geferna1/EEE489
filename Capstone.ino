//ALL code will be in this file, when testing one part, comment out the rest of the code or copy the section and paste in a seperate file. 
//Please leave comments whenever the code is updated.

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//BATTERY LEVEL Code
int value = 0;
float voltage;
float BatteryLevel;

void setup(){
  Serial.begin(9600);
}

void loop(){
  value = analogRead(A0);
  voltage = value * 5.0/1023;
  BatteryLevel = map(voltage, 3.6, 4.2, 0, 100);
  Serial.print("Voltage= ");
  Serial.println(voltage);
  Serial.print("Battery Level =");
  Serial.print(BatteryLevel);
  Serial.println(" %");
  delay(500);
}

//Batttery level conditional statements
const int LED_PIN = 5;
int pwm = 12; // assigns pin 12 to variable pwm

void setup(){
    pinMode( LED_PIN, OUTPUT );
}

void loop(){
  if (BatteryLevel < 50%) {
  const int DUTY = 64;
    analogWrite( LED_PIN, DUTY );
    digitalWrite(pwm, LOW); //sets motor speed low
} else {
  const int DUTY = 100;
  analogWrite( LED_PIN, DUTY );
  digitalWrite(pwm, HIGH); //sets motor speed high
}


}
//------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Additional PWM Code for DC Motor Control
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
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
 //Resources:
 //LED brightness using PWM https://www.deviceplus.com/arduino/the-basics-of-arduino-adjusting-led-brightness/#:~:text=You%20can%20easily%20switch%20an,use%20the%20%E2%80%9CPWM%E2%80%9D%20output.
 // Reading battery level https://forum.arduino.cc/t/battery-level-check-using-arduino/424054/8
 // Controlling motor using PWM https://www.circuitstoday.com/pwm-generation-and-control-using-arduino

 
 
