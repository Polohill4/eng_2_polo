
int x = 0 ;

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  for (x = 0; x <= 255; x++) {
    analogWrite(6, x);
    Serial.println(x);
    delay(10);
  }

  for ( x = 255; x >= 0;  x--) {
    analogWrite(6, x);
    Serial.println(x);
    delay(10);
  }
}
