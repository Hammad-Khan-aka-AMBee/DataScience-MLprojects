#include <WiFi.h>
#include <HTTPClient.h>

const char *ssid = "TP-LINK_CFDE04"; //my wifi id
const char *password = "my password"; //pwd
const char *serverUrl = "http://192.168.0.103:3000/sensor-data"; //port and server ip 

void setup() {
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

void loop() {
  if (Serial.available() > 0) {
    // Read data from Arduino
    String data = Serial.readStringUntil('\n');

    // Remove leading/trailing whitespace and newlines
    data.trim();

    if (data.length() > 0) {
      // Create JSON payload
      String payload = "{\"sensorData\":" + data + "}";

      // Make HTTP POST request
      HTTPClient http;
      http.begin(serverUrl);
      http.addHeader("Content-Type", "application/json");

      int httpCode = http.POST(payload);

      if (httpCode > 0) {
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);
        String response = http.getString();
        Serial.println(response);
      } else {
        Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    }
  }

  delay(15000); // Wait for 15 seconds before sending the next set of data
}
