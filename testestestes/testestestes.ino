/*int incomingByte;

  void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  }

  void loop() {
  // put your main code here, to run repeatedly:
  incomingByte += Serial.read();
  if(Serial.read()!=-1){
  Serial.println(incomingByte+1);
  }
  }
*/


#define joyBut_PIN 2 // Joystick button Pin
#define joyX_PIN A0 // Joystick X Pin = Built in LED
#define joyY_PIN A1 // Joystick X Pin = Built in LED
boolean joy_But = false;
int joyX_Value = 0;
int joyY_Value = 0;
void setup() {
  pinMode(joyBut_PIN, INPUT_PULLUP); // declare
  pinMode(joyX_PIN, INPUT); // declare
  pinMode(joyY_PIN, INPUT); // declare
  Serial.begin(115200);

}
void loop() {
  joy_But = digitalRead(joyBut_PIN);
  joyX_Value = analogRead(joyX_PIN);
  joyY_Value = analogRead(joyY_PIN);
  /*
    if (joyX_Value == 0) {
    joyX_Value = 255;
    }*/

  Serial.print(joy_But);
  Serial.print(" ");
  Serial.print(joyX_Value);
  Serial.print(" ");
  Serial.println(joyY_Value);
}
