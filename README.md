# meteo_station_uno
This projects aims to develop a weather station, using wireless comunication system that will send data collected by the sensors
to the user's smarthpone.
The meteo station frame includes:

- Anemometer
- Wind vane
- Rain gauge

We already include a temperature sensor:
- Temperature sensor v1.2

We use the following electronic devices:

- Arduino UNO (Master): It reads the data collected by the sensors and send it to the slave via the RX and TX pins.
- Lolin D1 mini Pro (Slave): It receives the data from the Master and send it via WiFi to an IoT app, Blynk.

In this repositorie there are two files:

- Estation: Which incldues the Arduino UNO (master) code. This code reads the data received by the different sensors and performs the necessary operations to transform the analog inputs and pulses into physical data. It includes the SoftwareSerial library, to establish the Serial Comunication between Rx and Tx I/O pins.

- Serial_communication_receiver:  Which includes the Lolin D1 mini PRO (slave) code. This code receives the data from the master, then analize it and send it via WiFi to the Blynk application. It includes the Blynk and the ESP8266Wifi libraries.

You must install the Blynk Library for your WiFi device and download the Blynk application in your mobile phone, it's available for
Android and iOS.

--- LINKS ---

Meteo Station guide: https://docs.google.com/presentation/d/1sDDvMkqmOyQTjW4TWZG4k4KzVs6vggXtB96XupOpIVQ/edit?usp=sharing

Get started now: https://blynk.io/en/getting-started

Meteo station (product): https://www.sparkfun.com/products/8942

Meteo station (hookup guide): https://learn.sparkfun.com/tutorials/weather-meter-hookup-guide?_ga=2.241424385.245433083.1579691653-1720560228.1577174229

Temperature sensor (product): http://wiki.seeedstudio.com/Grove-Temperature_Sensor_V1.2/

Lolin D1 mini Pro: https://wiki.wemos.cc/products:d1:d1_mini_pro
