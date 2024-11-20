#include <FirebaseESP32.h>

// Konfigurasi Firebase
#define FIREBASE_HOST "your-project-id.firebaseio.com"
#define FIREBASE_AUTH "your-database-secret"

FirebaseData firebaseData;

void setup() {
  WiFi.begin("SSID", "password");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
}

void loop() {
  int moistureLevel = analogRead(sensorPin); // Baca sensor kelembapan
  unsigned long timestamp = millis() / 1000; // Konversi ke detik
  
  // Menulis data ke Firebase
  Firebase.setInt(firebaseData, "/moistureData/sensor_1/moistureLevel", moistureLevel);
  Firebase.setInt(firebaseData, "/moistureData/sensor_1/timestamp", timestamp);

  delay(10000); // Update setiap 10 detik
}
