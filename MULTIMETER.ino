/* MULTIMETER ARDUINO PROGRAM
 * CREATED BY
 * ASTRID GLORIA P. - 18114001
 * KEINDA DWI ADILIA - 18114009
 * RIKO BOBOT P. - 18114010
 * TELECOMMUNICATION ENGINEERING
 * INSTITUT TEKNOLOGI BANDUNG
 */

// set reference voltage;
float refVcc = 5.0;
// Common anode
#define ON LOW
#define OFF HIGH
// Pin Definition
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define f 7
#define G 8
#define inPin 9
 
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize digital pin output
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(f,OUTPUT); 
  pinMode(G,OUTPUT);
  pinMode(inPin, INPUT);
}
 
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  float sensorValue1 = analogRead(A0);
  // print out the value you read:
  Serial.print("Analog read 0 : ");
  Serial.println(sensorValue1);
  // print out the converted (voltage) value
  Serial.print ("Voltage : ");
  float voltage0 = sensorValue1*refVcc/1024;
  Serial.print(voltage0);
  Serial.println(" V");
  float current = voltage0/100;
  Serial.print("Current if Resistor value is 100 ohm = ");
  Serial.print(current);
  Serial.println(" A");
  float power = voltage0*current;
  Serial.print("Power = ");
  Serial.print(power);
  Serial.println(" W");
  Serial.println("--------------------");
  int val = digitalRead(inPin);
  int i = 0;
  Serial.println(val);
  if (val = LOW) {
    int x = voltage0/1;
    float y = voltage0 - x;
    if (y>=0.50){
      x = x + 1;
    }
    i = x;
  }
  else {
    int p = current*100/1;
    float q = current*100 - p;
    if (q>=0.50) {
      p = p + 1;
    }
    i = p;
  } 
  sevensegmentOutput(i);
  delay(1000);        // delay a whole second before reading again
}
void sevensegmentOutput(int number){
  switch (number){
    case 0:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(f, ON);
        digitalWrite(G, OFF);
        break;
     case 1:
        digitalWrite(A, OFF);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(f, OFF);
        digitalWrite(G, OFF);
        break;
    case 2:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, OFF);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(f, OFF);
        digitalWrite(G, ON);
        break;
    case 3:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(f, OFF);
        digitalWrite(G, ON);
        break;
    case 4:
        digitalWrite(A, OFF);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
    case 5:
        digitalWrite(A, ON);
        digitalWrite(B, OFF);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
    case 6:
        digitalWrite(A, ON);
        digitalWrite(B, OFF);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
    case 7:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, OFF);
        digitalWrite(E, OFF);
        digitalWrite(f, OFF);
        digitalWrite(G, OFF);
        break;
    case 8:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, ON);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
    case 9:
        digitalWrite(A, ON);
        digitalWrite(B, ON);
        digitalWrite(C, ON);
        digitalWrite(D, ON);
        digitalWrite(E, OFF);
        digitalWrite(f, ON);
        digitalWrite(G, ON);
        break;
  }
}
