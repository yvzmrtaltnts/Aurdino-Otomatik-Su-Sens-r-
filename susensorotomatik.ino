#include <SoftwareSerial.h>

SoftwareSerial bluetooth(10, 11); // RX, TX pinleri (D10 ve D11)
const int suSensorPin = A0;     // Yağmur sensörü bağlantı pini
const int buzzerPin = 9;          // Buzzer bağlantı pini

void setup() {
  pinMode(suSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  int sensorDeger = analogRead(suSensorPin);
  float suSeviye = map(sensorDeger, 0, 1023, 100, 0); // Su seviyesini yüzde olarak hesapla
  
  Serial.print("Su Seviyesi (%): ");
  Serial.println(suSeviye);

  bluetooth.print("Su Seviyesi (%): ");
  bluetooth.println(suSeviye);

  // Su seviyesine göre alarm çal
  if (50 < suSeviye) {
    tone(buzzerPin, 1000); // Buzzer'ı 1000 Hz frekansında çal
  } else {
    noTone(buzzerPin); // Buzzer'ı kapat
  }

  delay(1000); // 1 saniye bekleme
}
