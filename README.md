Używamy Visial Studio Code z wtyczką PlatformoIO IDE

Pliki .cpp umieszczamy w pong_stm/src  
Pliki .hpp umieszczamy w pong_stm/include (.hpp zamiast .h aby rozróżniać kod C++ od C)  

STM podłączmy doa wyświetlacza w taki sposób:

<pre>
STM : Wyświetlacz
5V   ->  5V
GND  ->  GND
PD5  ->  WR
PD13 ->  RS
NRST ->  RST
PD7  ->  CS
PD14 ->  DB0
PD15 ->  DB1
PD0  ->  DB2
PD1  ->  DB3
PE7  ->  DB4
PE8  ->  DB5
PE9  ->  DB6
PE10 ->  DB7
PE11 ->  DB8
PE12 ->  DB9
PE13 ->  DB10
PE14 ->  DB11
PE15 ->  DB12
PD8  ->  DB13
PD9  ->  DB14
PD10 ->  DB15
</pre>

