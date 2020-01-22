// This function returns the value of the orientation of the wind vane.
int wind_direction(){

  int value = 0;
  unsigned int adc;

  adc = analogRead(WDIR); // get the current reading from the sensor
  
  // The following table is ADC readings for the wind direction sensor output, sorted from low to high.
  // Each threshold is the midpoint between adjacent headings. The output is degrees for that ADC reading.
  // Note that these are not in compass degree order! See Weather Meters datasheet for more information.

  if (adc < 70) return 0;
  if (adc < 130) return 315;
  if (adc < 200) return 270;
  if (adc < 320) return 45;
  if (adc < 440) return 225;
  if (adc < 550) return  90;
  if (adc < 630) return 135;
  if (adc < 660) return 180;
  
}
