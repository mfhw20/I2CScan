//I2CScan.h

#ifndef __I2CSCAN__
#define __I2CSCAN__

#include <Wire.h>

// https://www.az-delivery.de/blogs/azdelivery-blog-fur-arduino-und-raspberry-pi/esp32-beide-i-c-schnittstellen-verwenden

#define I2C_ONE
#define I2C_TWO

#ifdef I2C_ONE
#define SDA1 33
#define SCL1 32
#endif

#ifdef I2C_TWO
#define SDA2 17
#define SCL2 16
#endif

void scan(TwoWire I2Cbus, uint channel, uint sda, uint scl);

#endif