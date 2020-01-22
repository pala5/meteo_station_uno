void serial_communication()
{
  Uno.print("S"); //secure word to start the communication 
  Uno.print(windSpeed);
  Uno.print("\r"); //retorno de carro
  delay(10);
  Uno.print("K");
  Uno.print(windSpeed_kmh);
  Uno.print("\r"); //retorno de carro
  delay(10);
  Uno.print("R");
  Uno.print(rainCounter);
  Uno.print("\r"); //retorno de carro
  delay(10);
  Uno.print("D");   
  Uno.print(windDir);
  Uno.print("\r"); //retorno de carro
  delay(10);
  Uno.print("T");
  Uno.print(temperature);
  Uno.print("\r"); //retorno de carro
  delay(100);
}
