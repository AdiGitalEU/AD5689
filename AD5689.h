/*
 Name:		AD5689.h
 Created:	5/2/2018 4:16:22 PM
 Author:	adi
 Editor:	http://www.visualmicro.com
*/

#ifndef _AD5689_h
#define _AD5689_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

#define CMD_WRITE_TO_INPUT_REG				0b0001	//dependant on LDAC input
#define CMD_UPDATE_DAC_WITH_INPUT_REG		0b0010
#define CMD_WRITE_AND_UPDATE_DAC			0b0011
#define CMD_POWER_UP_DOWN_DAC				0b0100
#define CMD_HARDWARE_LDAC_MASK				0b0101
#define CMD_SOFWARE_RESET					0b0110
#define CMD_DAISY_CHAIN_ENABLE				0b1000
#define CMD_READBACK_ENABLE					0b1001

#define ADDR_DAC_A							0b0001
#define ADDR_DAC_B							0b1000
#define ADDR_DAC_AB							0b1001


class AD5689 {
public:
	AD5689(SPISettings spiConf, uint8_t CSpin);
	void SetChannel(uint8_t channel, uint16_t vOut);

private:
	SPISettings _spiConf;
	uint8_t		_CSpin;
};

#endif

