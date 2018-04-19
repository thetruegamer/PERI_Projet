int val; // value from the sensor will be stored here
unsigned long period_in_milliseconds;

void setup() {
  // initialize serial communication at 9600 bits per second for testing purposes
  Serial.begin(9600);
  
  period_in_milliseconds = 60000; // currently we read the value every minute
}

void loop() {
  val = analogRead(15);

  Serial.println(val); // Testing line, to remove when done
  
  // TODO send value through network

  // we wait before we read and send again
  delay(period_in_milliseconds);
}
