// Calculates the temperature with 5 V input signal.
void get_temperature()
{
  int a = analogRead(TEMP);

  float R = 1023.0/a-1.0;
  R = R0*R;

  temperature = 1.0 / (log(R/R0)/ B + 1/298.15)-273.15;
}
