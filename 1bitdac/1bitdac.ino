long int start_time;
short int state;

void setup() {
  Serial.begin(115200);
  pinMode(6, OUTPUT);
  start_time = millis();
  state = 0;
}  

void loop() {
  long int current_time = millis();
  if (current_time - start_time <= 3000) {
    if (state == 0) {
      // speaker off
      digitalWrite(5, 0);
      state = 1;
    }
  } else if (current_time - start_time <= 6000) {
    if (state == 1) {
      // speaker on
      digitalWrite(5, 1);
      state = 2;
    }
  } else {
    // start loop over
    start_time = millis();
    state = 0;
  }
}
