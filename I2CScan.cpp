#include <Arduino.h>
#include <I2CScan.h>

void scan(TwoWire I2Cbus, uint channel, uint sda, uint scl)
{
    Serial.printf("Scanning I2C Addresses Channel %d SDA %d SCL %d", channel, sda, scl);
    Serial.println();
    uint8_t cnt=0;
    for(uint8_t i=0; i<128; i++)
    {
        I2Cbus.beginTransmission(i);
        uint8_t ec=I2Cbus.endTransmission(true);
        if(ec == 0)
        {
            if(i < 16)   
                Serial.print('0');
            Serial.print(i, HEX);
            cnt++;
        }
        else
            Serial.print("..");

        Serial.print(' ');
        if ((i & 0x0f) == 0x0f)
            Serial.println();
    }
    Serial.print("Scan Completed, ");
    Serial.print(cnt);
    Serial.println(" I2C Devices found.");
}