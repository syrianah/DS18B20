## Example for DS18B20 sensor

### Tutorial:

Tutorial I use is [link](http://akademia.nettigo.pl/ds18b20/)

### Code description:

To get sensor adress you need to run [code](https://gitlab.com/putrocketlab/it/-/blob/develop/Hexa2/Examples/DS18b20/DS18b20CheckAdress.ino)

To read temperature you need to run [code](https://gitlab.com/putrocketlab/it/-/blob/develop/Hexa2/Examples/DS18b20/DS18b20ReadTemp.ino)

### Library:

If download from internet change or get lib from our gitlab

```c++
#include <avr/pgmspace.h>
```

to this

```c++
#ifdef __AVR__
#include <avr/pgmspace.h>
#elif defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#endif
```

Library OneWire is available at: [link](http://akademia.nettigo.pl/ds18b20/OneWire.zip)

Library DS18B20 is available at: [link](http://akademia.nettigo.pl/ds18b20/DS18B20.zip)

See also [link](https://github.com/milesburton/Arduino-Temperature-Control-Library)

### Connections:

![Image 4](https://gitlab.com/putrocketlab/it/-/raw/develop/Hexa2/Examples/DS18b20/ds18b20_single.png "Connections")
