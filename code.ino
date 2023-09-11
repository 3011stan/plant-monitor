#include <HTTPClient.h>

void setup() {
  // Sua configuração aqui
}

void loop() {
  if(WiFi.status()== WL_CONNECTED){ 
    HTTPClient http;  
    http.begin("http://<Seu_IP_Externo>:3000/sensor");
    http.addHeader("Content-Type", "application/json"); 

    int httpResponseCode = http.POST("{\"temperature\":24.5, \"humidity\":40.0, \"light\":300.0}");
 
    if(httpResponseCode>0){
      String response = http.getString();  
      Serial.println(httpResponseCode);  
      Serial.println(response); 
    }
    else{
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end(); 
  }
  delay(60000);  // Espera 1 minuto antes de enviar novamente
}
