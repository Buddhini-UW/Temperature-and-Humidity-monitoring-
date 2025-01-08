#include "arduino_secrets.h"
#include <DHT.h>
#include <DHT_U.h>


#define DHTPIN 4    
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  delay(1500); 

  Serial.println("DHT22 test!");
  dht.begin();
  // Defined in thingProperties.h
  initProperties();
  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  humidity = hum;
  temperature = temp;
  message = "Temperature: "+String(temp)+"  Humidity: "+String(hum);

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%  Temperature: ");
  Serial.print(temp);
  Serial.println("°C");
  delay(2000); // Wait a bit between readings
}


/*
  Since Humidity is READ_WRITE variable, onHumidityChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumidityChange()  {
  // Add your code here to act upon Humidity change
}


void onTemperatureChange()  {
  // Add your code here to act upon Temperature change
}

/*
  Since Message is READ_WRITE variable, onMessageChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMessageChange()  {
  // Add your code here to act upon Message change
}
