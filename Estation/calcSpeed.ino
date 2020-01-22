void calcSpeed ()
{
//  windSpeed = ((4*pi*radio*RPM)/60)/1000; //Calcula la velocidad del viento en [m/s]
    windSpeed = (windCounter * 1000 * 2 * pi) / (period * 3);
}
