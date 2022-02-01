// Program odczytuje temperaturę z czujnika

#include <OneWire.h>
#include <DS18B20.h>

// Numer pinu do którego podłaczasz czujnik
#define ONEWIRE_PIN 2

// Adres czujnika
byte address[8];
//byte address[8] = {0x28, 0x14, 0xEB, 0x8E, 0x5B, 0x14, 0x1, 0xCC};

OneWire onewire(ONEWIRE_PIN);
DS18B20 sensors(&onewire);

unsigned long old_time;
unsigned long new_time;

// --------------------------------------------------------
// setup ds18b20
void setupDS()
{
    onewire.reset_search();
    while (onewire.search(address))
    {
        if (address[0] != 0x28)
            continue;

        if (OneWire::crc8(address, 7) != address[7])
        {
            Serial.println(F("Błędny adres, sprawdz polaczenia"));
            break;
        }
        Serial.print("[INFO] [setupDS] adres czujnka temperatury = ");
        for (byte i = 0; i < 8; i++)
        {
            Serial.print(F("0x"));
            Serial.print(address[i], HEX);

            if (i < 7)
                Serial.print(F(", "));
        }
        Serial.println();
    }
}

void setup()
{

  while (!Serial)
    ;
  Serial.begin(9600);

  setupDS();
  sensors.begin();
  sensors.request(address);
  new_time = millis();
}

void loop()
{
  //  unsigned long  time_0 = millis();
  //  unsigned long time_;
  if (sensors.available())
  {
    float temperature = sensors.readTemperature(address);

    //    Serial.println(millis()-new_time);
    //    old_time = new_time;

    Serial.print(millis() - new_time);
    Serial.print("\t");
    Serial.print(temperature);
    //  Serial.println(F(" 'C"));

    sensors.request(address);
  }

  // tu umieść resztę twojego programu
  // Będzie działał bez blokowania
}
