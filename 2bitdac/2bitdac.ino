long int start_time;
short int state;

void setup() {
  Serial.begin(115200);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  start_time = millis();
  state = 0;
}  

void loop() {
  long int current_time = millis();
  if (current_time - start_time <= 1000) {
    if (state == 0) {
      // v1 off, v2 off
      Serial.println("v1 off, v2 off");
      digitalWrite(7, 0);
      digitalWrite(6, 0);
      state = 1;
    }
  } else if (current_time - start_time <= 2000) {
    if (state == 1) {
      // v1 on, v2 off
      Serial.println("v1 on, v2 off");
      digitalWrite(7, 1);
      digitalWrite(6, 0);
      state = 2;
    }
  } else if (current_time - start_time <= 3000) {
    if (state == 2) {
      // v1 off, v2 on
      Serial.println("v1 off, v2 on");
      digitalWrite(7, 0);
      digitalWrite(6, 1);
      state = 3;
    }
  } else if (current_time - start_time <= 4000) {
    if (state == 3) {
      // v1 on, v2 on
      Serial.println("v1 on, v2 on");
      digitalWrite(7, 1);
      digitalWrite(6, 1);
      state = 4;
    }
  } else {
    // start loop over
    start_time = millis();
    state = 0;
  }
}
