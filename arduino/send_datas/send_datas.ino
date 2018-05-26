#include<SPI.h>
#include<RF24.h>

RF24 radio(9,10);

int val; // value from the sensor will be stored here
unsigned long period_in_milliseconds;

// setup the radio communication
// pipe adress for communicating, we put some random things, just make sure it's the same on the Pi
byte addresses[][6] = {"0CLBM"};

void setupRadio(void) {
  radio.begin();
//  radio.setRetries(15,15);
  radio.setPALevel(RF24_PA_LOW);
  radio.openWritingPipe(addresses[0]);
  radio.printDetails();
}

void setup() {
  // initialize serial communication at 9600 bits per second for testing purposes
  Serial.begin(9600);

  setupRadio();
  period_in_milliseconds = 1000; // currently we read the value every minute
}

void loop() {
  // read the value from the light sensor
  val = analogRead(15);

  Serial.println(val); // Testing line, to remove when done

  // send value through radio
  radio.write(&val, sizeof(val));

  // we wait before we read and send again
  delay(1000);
}
