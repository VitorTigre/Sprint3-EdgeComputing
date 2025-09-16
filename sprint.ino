#include <WiFi.h>
#include <HTTPClient.h>


const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Configurações do ThingSpeak
const char* server = "api.thingspeak.com";
String apiKey = "AF5OYISWMCPFGIBY"; //

void setup() {
  Serial.begin(115200);
  connectWiFi();
}

void loop() {
  int heartRate = random(60, 180);
  int oxygenLevel = random(95, 100); 
  int accelX = random(-20, 20);
  int accelY = random(-20, 20); 
  int accelZ = random(-20, 20);


  sendToThingSpeak(heartRate, oxygenLevel, accelX, accelY, accelZ);
  delay(5000);
}

void connectWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Conectando ao WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void sendToThingSpeak(int heartRate, int oxygen, int x, int y, int z) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    
    String url = "http://" + String(server) + "/update?api_key=" + apiKey +
                 "&field1=" + String(heartRate) +
                 "&field2=" + String(oxygen) +
                 "&field3=" + String(x) +
                 "&field4=" + String(y) +
                 "&field5=" + String(z);
    
    http.begin(url);
    int httpCode = http.GET();
    
    if (httpCode == 200) {
      Serial.println("Dados enviados com sucesso!");
      String response = http.getString();
      Serial.println("Resposta: " + response);
    } else {
      Serial.printf("Falha no envio. Código HTTP: %d\n", httpCode);
      Serial.printf("Erro: %s\n", http.errorToString(httpCode).c_str());
    }
    
    http.end();
  } else {
    Serial.println("WiFi desconectado");
    connectWiFi();
  }
}
