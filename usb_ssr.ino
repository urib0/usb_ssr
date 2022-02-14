#define STATUS_OK 0
#define VERSION "1.00"
#define INTERVAL_UPDATE 1000
#define PIN 1

void setup() {
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  digitalWrite(PIN, LOW);
  while (!Serial) delay(1);
}

void loop() {
  static char buf = '0';
  static char null = 0;

    // 入力処理
  if (Serial.available() > 0)
  {
    buf = Serial.read();

    // 受信バッファをクリア
    while (Serial.available() > 0){
      null = Serial.read();
    }
  }

  if (buf == '1'){
    digitalWrite(PIN, HIGH);
  }
  else{
    digitalWrite(PIN, LOW);
  }
  Serial.print("ssr=");
  Serial.print(buf);
  Serial.print(";status=");
  Serial.print(STATUS_OK);
  Serial.print(";version=");
  Serial.print(VERSION);
  Serial.print("\n");

  delay(INTERVAL_UPDATE);
}
