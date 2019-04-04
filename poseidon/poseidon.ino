// Information on string conversion https://docs.particle.io/reference/device-os/firmware/photon/#string-class
// MiCS-5524 senso

String analogvalue;

void setup() {
  Serial.begin(115200);
  Serial.println("MiCS-5524 is running!");
  Particle.variable("analogvalue", analogvalue);
}

void loop() {
  String analogvalue = String(analogRead(A0));
  Particle.publish("analogvalue", analogvalue);
  // Wait for 30 seconds
  delay(30000);               
}