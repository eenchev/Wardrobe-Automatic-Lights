/*
  Connect the two reed switches (front and back doors) as follows:
   -GPIO 13 and GND via 10kOhm resistor / 3.3V
   -GPIO 4 and GND via 10kOhm resistor / 3.3V

   The board used is ESP12F based, single NC-NO relay (PIN 5), programmable led (PIN 16). Board can be powered via microUSB or 220V or low voltage DC. 
   Board image: https://lh3.googleusercontent.com/proxy/JffZhaeeIyklySQSGw1TruRaNhQK-756zExFdg88MFD-dL_fKN2MRcVQAjEGpv1QAeB_KOf_iNUdbX62h2gxnUMJV6rTobRWE-weRTHk4ZvWNSZ2DdOzBgdLHaM
   Board docs: https://www.mediafire.com/file/ha2grpl0c5obyt3/LC-Relay-ESP12-1R-MV_EN.zip/file
  */
#define PIN_LED 16
#define PIN_RELAY 5
#define PIN_DOOR_LEFT 13
#define PIN_DOOR_RIGHT 4

bool doorStatusLeft = false;
bool doorStatusRight = false;
bool doorStatusCombined = false;

void setup ()
{
  pinMode(PIN_DOOR_LEFT, INPUT_PULLUP);
  pinMode(PIN_DOOR_RIGHT, INPUT_PULLUP);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_RELAY, OUTPUT);
  digitalWrite(PIN_LED, LOW); 
  digitalWrite(PIN_RELAY, LOW);
}
void loop ()
{
  doorStatusLeft = (digitalRead(PIN_DOOR_LEFT) == HIGH);
  doorStatusRight = (digitalRead(PIN_DOOR_RIGHT) == HIGH);
  doorStatusCombined = doorStatusLeft && doorStatusRight;
  if (!doorStatusCombined) {
    digitalWrite(PIN_LED, HIGH);
    digitalWrite(PIN_RELAY, HIGH);
  } else {
    digitalWrite(PIN_LED, LOW);
    digitalWrite(PIN_RELAY, LOW);
  }

  delay(1500);
}
