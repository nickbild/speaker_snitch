#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <WiFiNINA.h>

#include "arduino_secrets.h" 
char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int keyIndex = 0;

int status = WL_IDLE_STATUS;
WiFiServer server(80);

#define PIN 6
#define NUMPIXELS 1

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();

  Serial.begin(9600);      // initialize serial communication

  if (WiFi.status() == WL_NO_MODULE) {
    Serial.println("Communication with WiFi module failed!");
    while (true);
  }

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);

    printWifiStatus();
  }

  server.begin();
}

void loop() {
  pixels.clear();

  WiFiClient client = server.available();
  if (client) {
    Serial.println("new client");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("Click <a href=\"/H\">here</a> turn the LED on pin 9 on<br>");
            client.print("Click <a href=\"/L\">here</a> turn the LED on pin 9 off<br>");
            client.println();
            break;

          } else {
            currentLine = "";
          }

        } else if (c != '\r') {
          currentLine += c;
        }

        if (currentLine.endsWith("GET /on")) {

          for (int j=0; j<10; j++) {
            for(int i=0; i<255; i++) {
              pixels.setPixelColor(0, pixels.Color(i, 0, 0));
              pixels.show();
              delay(5);
            }
          
            for(int i=255; i>0; i--) {
              pixels.setPixelColor(0, pixels.Color(i, 0, 0));
              pixels.show();
              delay(5);
            }
          }

        }

        if (currentLine.endsWith("GET /off")) {

          pixels.clear();
          pixels.show();
        }

      }

    }

    client.stop();
    Serial.println("client disonnected");

  }
  
}

void printWifiStatus() {
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}
