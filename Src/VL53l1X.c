#include "stm32l4xx_hal.h"
#include "VL53l1X.h"


//Start the Data Initializer
void VL53L1_DataInit(I2C_HandleTypeDef i2cHandle) {
	
	uint8_t buffer[12];
	buffer[0] = 0x88;
	buffer[1] = 0x00;
	
	HAL_I2C_Master_Transmit(&i2cHandle, 0x52, buffer, 2, 100);
	HAL_Delay(20);

}

//Start the Static Initializer
void VL53L1_StaticInit(I2C_HandleTypeDef i2cHandle) {
	uint8_t buffer[12];
	buffer[0] = 0xFF;
	buffer[1] = 0x01;
	HAL_I2C_Master_Transmit(&i2cHandle, 0x52, buffer, 2, 100);
	
	uint16_t tempword = 0;
	
	buffer[0] = 0xFF;
	buffer[1] = tempword;
	HAL_I2C_Master_Receive(&i2cHandle, 0x53, buffer, 2, 100);
	
	
	buffer[0] = 0xFF;
	buffer[1] = 0x00;
	HAL_I2C_Master_Transmit(&i2cHandle, 0x52, buffer, 2, 100);

	
}

// This function will get the measurement ready
void VL53L1_StartMeasurement(I2C_HandleTypeDef i2cHandle) {
	uint8_t buffer[64];
	buffer[0] = 0x000;
	buffer[1] = 0x01;
	HAL_I2C_Master_Transmit(&i2cHandle, 0x52, buffer, 2, 100);
}





