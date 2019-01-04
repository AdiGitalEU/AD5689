/*
 This example generates oposite sinewaves about 1 Hz
  
 Pins configuration for testing chip/library:
 
 1  - AD5689 = VDD, AD5689R = not connected. AD5689R uses internal or external voltage reference, AD5689 uses external only.
 2  - not connected
 3  - analog output A
 4  - GND
 5  - VDD            (2.7 - 5.5V - match with your controller voltage)
 6  - not connected
 7  - analog output B
 8  - not connected  (SDO)
 9  - GND            (LDAC)
 10 - GND            (Gain)
 11 - VDD            (V logic)
 12 - SCLK           (Arduino Uno pin 13 - SPI:SCK)
 13 - SYNC/CS        (Any digital pin)
 14 - SDIN           (Arduino Uno pin 11 - SPI:MOSI)
 15 - VDD            (RESET)
 16 - GND            (RSTSEL)
 
 Current functions:
 AD5689(SPISettings spiConf, uint8_t CSpin)
 AD5689(SPISettings spiConf, uint8_t CSpin, uint8_t ResetPin)
 void SetChannel(uint8_t channel, uint16_t vOut)
 void SetReference(uint8_t source)  for AD5689R source can be EXTERNAL or INTERNAL(default)
 void SoftReset()
 void HardReset() if reset pin 15 is connected
 */
#include <AD5689.h>

#define CS_DAC_Pin 10
#define SPI_Clock  1000000 //max clock on Arduino Uno (ATMega 328 16MHz) is 8MHz 8000000, AD5689 works up to 50MHz

AD5689 DAC(SPISettings(SPI_Clock, MSBFIRST, SPI_MODE1), CS_DAC_Pin);

void setup() {
  DAC.SoftReset();
}

void loop() {
  float base = millis()/1000.0f;
  uint16_t value = 32767.0f + 32766 * sin(base * 2.0f * PI);
  DAC.SetChannel(0, value);
  DAC.SetChannel(1, -value);
}
