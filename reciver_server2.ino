#include <SPI.h>
#include <LoRa.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Define the pins used by the transceiver module
#define ss 5
#define rst 14
#define dio0 2

const char *ssid = "ESP32-AP";
const char *password = "password";

AsyncWebServer server(80);

// Arrays to store the data
int heartRateData;
float spo2Data;
float temperatureData;

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver");

  // Setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);

  // Replace the LoRa.begin(---E-) argument with your location's frequency
  // 433E6 for Asia
  // 866E6 for Europe
  // 915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }

  // Change sync word (0xF3) to match the transmitter
  LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");

  // Set up the Access Point
  WiFi.softAP(ssid, password);
  IPAddress ip = WiFi.softAPIP();
  Serial.println("AP IP address: " + ip.toString());

  // Route for root
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String html = "<html><head>";
    html += "<style>body{font-family: Arial, sans-serif; text-align: center; margin: 50px; background-color: #f0e6e6;}"
            "h1{color: #ff8080; font-size: 36px; margin-bottom: 20px;} p{font-size: 24px; color: #cc6666;}"
            "#data-box{border: 2px solid #ffcccc; padding: 20px; margin: 20px; text-align: center; background-color: #ffe6e6; border-radius: 10px;}"
            "</style>";
    html += "<meta http-equiv='refresh' content='1'></head><body>";
    html += "<h1>LoRaMED Healthcare</h1>";
    html += "<div id='data-box'>";
    html += "<p><strong>Heartrate:</strong> " + String(heartRateData) + "</p>";
    html += "<p><strong>SpO2:</strong> " + String(spo2Data) + "</p>";
    html += "<p><strong>Temperature:</strong> " + String(temperatureData) + " °F</p>";
    html += "</div>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  // Start server
  server.begin();
}

void handleReceivedData(String receivedData) {
  // Convert the received String to a C-style string
  char dataBuffer[50];
  receivedData.toCharArray(dataBuffer, 50);

  // Use strtok to tokenize the string based on the comma
  char *token = strtok(dataBuffer, ",");

  // Parse the heart rate
  heartRateData = atoi(token);

  // Move to the next token for SpO2
  token = strtok(NULL, ",");
  spo2Data = atof(token);

  // Move to the next token for Temperature
  token = strtok(NULL, ",");
  temperatureData = atof(token);
}

void loop() {
  // Try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // Received a packet
    Serial.print("Received packet '");

    // Read packet and store in the global variable
    String receivedData = "";
    while (LoRa.available()) {
      receivedData += LoRa.readString();
    }
    Serial.print(receivedData);
    handleReceivedData(receivedData);

    // Print RSSI of packet
    Serial.print("' with RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
