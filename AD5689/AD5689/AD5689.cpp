
/*
Name:		AD5689.cpp
Created:	5/2/2018 9:45:56 AM
Author:	adi
Editor:	http://www.visualmicro.com
*/

#include "AD5689.h"

AD5689::AD5689(SPISettings spiConf, uint8_t CSpin) {
	_spiConf = spiConf;
	_CSpin = CSpin;
	pinMode(_CSpin, OUTPUT);
}

void AD5689::SetChannel(uint8_t channel, uint16_t vOut) {
	SPI.beginTransaction(_spiConf);
	digitalWrite(_CSpin, LOW);
	switch (channel) {
	case 0:
		SPI.transfer((CMD_WRITE_TO_INPUT_REG << 4) | ADDR_DAC_A);
		break;
	case 1:
		SPI.transfer((CMD_WRITE_TO_INPUT_REG << 4) | ADDR_DAC_B);
		break;
	default:
		return;
	}
	SPI.transfer(vOut >> 8);
	SPI.transfer(vOut);
	digitalWrite(_CSpin, HIGH);
	SPI.endTransaction();
}

