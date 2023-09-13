#include <SPI.h>
#include <WiFiNINA.h>

const char* ssid = "AndroidHotspot2862";       // WiFi의 SSID(수정필요)
const char* pass = "2862ywjywj";     // WiFi의 비밀번호(수정필요)

int status = WL_IDLE_STATUS;
int SensorPin = A0; //analog pin 0
int serverPort=12345;
WiFiServer server(serverPort);
 
void setup(){
  Serial.begin(115200);

  
   // 와이파이 연결시도(연결이 되어 있지 않을때만 실행)
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to WPA SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network:
    status = WiFi.begin(ssid, pass);
    // wait 5 seconds for connection:
    delay(5000);
  }
    // you're connected now, so print out the data:
  Serial.println("You're connected to the network");
}
 
void loop(){
  //WiFiClient client = server.available();

  int SensorReading = analogRead(SensorPin); 
 
  int mfsr_r18 = map(SensorReading, 0, 1024, 0, 255);
  Serial.println(mfsr_r18);

  
  
  delay(100); 
}
