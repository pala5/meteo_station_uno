# meteo_station_uno
This projects aims to develop a weather station, using wireless comunication system that will send data collected by the sensors
to the user's smarthpone.
The meteo station frame includes:
- Anemometer
- Wind vane
- Rain gauge
We already include a temperature sensor: Temperature sensor v1.2 
We use the following electronic devices:
- Arduino UNO (Master): It reads the data collected by the sensors and send it to the slave via the RX and TX pins.
- Lolin D1 mini Pro (Slave): It receives the data from the Master and send it via WiFi to an IoT app, Blynk.
You must install the Blynk Library for your WiFi device and download the Blynk application in your mobile phone, it's available for
Android and iOS.
--- LINKS ---
Get started now: https://blynk.io/en/getting-started
Meteo station (product): https://www.sparkfun.com/products/8942
Meteo station (hookup guide): https://learn.sparkfun.com/tutorials/weather-meter-hookup-guide?_ga=2.241424385.245433083.1579691653-1720560228.1577174229
Temperature sensor (product): http://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/
Lolin D1 mini Pro: https://wiki.wemos.cc/products:d1:d1_mini_pro
