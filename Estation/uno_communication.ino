// Establish the communication with the slave WiFi board (Lolin D1 mini PRO)
void uno_communication()
{
  Uno.print('W');
  Uno.print(windSpeed);
  Uno.print('\r');
  Uno.print('K');
  Uno.print(windSpeed_kmh);
  Uno.print('\r');
  Uno.print('R');
  Uno.print(rainCounter);
  Uno.print('\r');  
  Uno.print('D');
  Uno.print(windDir);
  Uno.print('\r');
  Uno.print('T');
  Uno.print(temperature);
  Uno.print('\r');
}
