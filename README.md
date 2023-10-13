# SHTC3_Compensated_SGP40_Test
VOC Index compensated by the temperature and humidity readings from an environmental sensor.

Adafruit has an example using the sht31 however I have the much more popular shtc3, which is slightly different in code. This lil project is a basic example of how to use the SHTC3 and SGP40 sesors together to get a more accurate readout for the voc (Volatile Organic Compounds) index, letting you know with confidence how bad or good the air quality is in a room when left on for more than 15 minutes. The SGP40 sensor is self-calibrating, so it needs some time to start up and give you more acccurate readings, but it works great to detect immediate changes right away, so it can be useful for things like checking whether the milk has gone bad and other stuff. I hope this is helpful to someone out there!
![image](https://github.com/poevoid/SHTC3_Compensated_SGP40_Test/assets/65972401/d819c84d-0298-4daa-9def-65d46b6939bf)
