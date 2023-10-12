/*************************************************** 
  This is an example for the SHTC3 Humidity & Temp Sensor

  Designed specifically to work with the SHTC3 sensor from Adafruit
  ----> https://www.adafruit.com/products/4636

  These sensors use I2C to communicate, 2 pins are required to  
  interface
 ****************************************************/

#include "Adafruit_SHTC3.h"
#include "Adafruit_SGP40.h"

Adafruit_SGP40 mox; //metal oxide sensor
Adafruit_SHTC3 envi = Adafruit_SHTC3(); //environmental sensor (temp/humidity)

void setup() {
  Serial.begin(115200);

  while (!Serial)
    delay(10);     // will pause Zero, Leonardo, etc until serial console opens

  Serial.println("SHTC3 test");
  if (! envi.begin()) {
    Serial.println("Couldn't find SHTC3");
    while (1) delay(1);
  }
  Serial.println("Found SHTC3 sensor");
  if (! mox.begin()){
    Serial.println("SGP40 sensor not found :(");
    while (1);
  }
  Serial.println("Found SGP40 sensor");
}


void loop() {
  sensors_event_t humidity, temp;
  int32_t voc_index;
  envi.getEvent(&humidity, &temp);// populate temp and humidity objects with fresh data
  voc_index = mox.measureVocIndex(temp.temperature, humidity.relative_humidity);
  Serial.print("Temperature: "); Serial.print(temp.temperature*1.8+32); Serial.println(" degrees F");
  Serial.print("Humidity: "); Serial.print(humidity.relative_humidity); Serial.println("% rH");
  Serial.print("VOC Index: "); Serial.println(voc_index);
  delay(1000);
}
