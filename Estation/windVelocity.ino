void windVelocity()
{
  //Reseteamos las variables globales
  windSpeed = 0;
  speedWind = 0;

  //Reseteamos el contador
  windCounter = 0;
  
  unsigned long millis();
  long startTime = millis();
  while(millis() < startTime + period){} //Esperamos a que millis() sea mayor a startTime+period
  
}
