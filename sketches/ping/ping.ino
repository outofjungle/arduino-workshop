void setup() {
  Serial1.begin(9600);
}

void loop() {
  ping();
  if (Serial1.available()) {
    Serial1.write(Serial1.read());
  }
}

void ping() {
  static long lasttime;
  if ((lasttime + 60000) < millis()) {
    Serial1.write("Ping!");
    lasttime = millis();
  }
}
