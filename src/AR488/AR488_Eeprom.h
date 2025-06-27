#ifndef AR488_EEPROM_H
#define AR488_EEPROM_H

#include "AR488_Config.h"
//#include <EEPROM.h>

/***** AR488_Eeprom.h, ver. 0.01.05, 26/06/2025 *****/

/*
 * EEPROM SIZES:
 * 
 * ATmega2560/1284   4096   // Mega 2560, MightyCore 1284 
 * ATmega644         2048   // MightyCore 644
 * ATmega328/32u4    1024   // Uno, Nano, Leonardo
 * ATmega168          512
 * ATmega4809         256   // Nano Every
 * ESP8266/ESP32     none   // Emulated. 512kb assigned?
 */


#if defined (__AVR__) || defined (ESP32)


#define EESIZE 256
#define EESTART 2    // EEPROM start of data - min 4 for CRC32, min 2 for CRC16
#define UPCASE true


const uint16_t eesize = EESIZE;


/*
 * EEPROM function declarations
 */


void epErase();
void epWriteData(uint8_t cfgdata[], size_t cfgsize);
bool epReadData(uint8_t cfgdata[], size_t cfgsize);
void epViewData(Stream& outputStream);
bool isEepromClear();


#endif  // defined (__AVR__) || defined (ESP32)

#endif  // AR488_EEPROM_H
