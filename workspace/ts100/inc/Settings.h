/*
 * Settings.h
 *
 *  Created on: 29 Sep 2016
 *      Author: Ralim
 *
 *      Houses the system settings and allows saving / restoring from flash
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_
#include <stdint.h>
#include "stm32f10x_flash.h"
#define SETTINGSVERSION 0x05 /*Change this if you change the struct below to prevent people getting out of sync*/
#define SETTINGSOPTIONSCOUNT 7 /*Number of settings in the settings menu*/
#define MOTION_HIGH (0x00)
#define MOTION_MED  (0x10)
#define MOTION_LOW  (0x20)
/*
 * This struct must be a multiple of 2 bytes as it is saved / restored from flash in uint16_t chunks
 */
struct {
	uint32_t SolderingTemp; 		//current set point for the iron
	uint32_t SleepTemp; 			//temp to drop to in sleep
	uint8_t version;				//Used to track if a reset is needed on firmware upgrade
	uint8_t SleepTime; 				//minutes timeout to sleep
	uint8_t cutoutVoltage:5; 		//The voltage we cut out at for under voltage
	uint8_t movementEnabled:1;		//If movement is enabled
	uint8_t displayTempInF:1;		//If we need to convert the C reading to F
	uint8_t flipDisplay:1;			//If true we want to invert the display for lefties
	uint8_t sensitivity:7;			//Sensitivity of accelerometer
	uint8_t ShutdownTime:7;			//Time until unit shuts down if left alone
	uint16_t tempCalibration;		//Temperature calibration value
	uint16_t voltageDiv;			//Voltage divisor factor
} systemSettings;

void saveSettings();
void restoreSettings();
void resetSettings();
#endif /* SETTINGS_H_ */
