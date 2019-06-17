#include "stm32l4xx_hal.h"




void VL53L1_DataInit(I2C_HandleTypeDef i2cHandle);
void VL53L1_StaticInit(I2C_HandleTypeDef i2cHandle);
void VL53L1_StartMeasurement(I2C_HandleTypeDef i2cHandle);
//void VL53L1_GetMeasurementDataReady(I2C_HandleTypeDef i2cHandle, uint8_t *pMeasurementDataReady);
//void VL53L1_GetRangingMeasurementData(I2C_HandleTypeDef i2cHandle, VL53L1_RangingMeasurementData_t *pRangingMeasurementData);
//void VL53L1_ClearInterruptAndStartMeasurement(I2C_HandleTypeDef i2cHandle, uint32_t InterruptClear);
//void VL53L1_StopMeasurement(I2C_HandleTypeDef i2cHandle);

