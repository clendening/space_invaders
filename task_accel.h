/*
 * task_accelerometer.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */
#include <main.h>

#ifndef TASK_ACCELEROMETER_H_
#define TASK_ACCELEROMETER_H_

/* tilt left threshold */
#define VOLT_1P6    7943        // 1.60 / (3.3 / 16383)
#define VOLT_1P55   7695        // 1.55
#define VOLT_1P5    7447        // 1.50
#define VOLT_1P45   7199        // 1.45

/* tilt right threshold */
#define VOLT_1P7    8440        // 1.7 / (3.3 / 16383)
#define VOLT_1P75   8688        // 1.75
#define VOLT_1P8    8936        // 1.8
#define VOLT_1P85   9184        // 1.85

extern TaskHandle_t Task_Accelerometer_Handle;
extern TaskHandle_t Task_Accelerometer_Timer_Handle;

extern volatile uint32_t ACCEL_X_DIR;

typedef enum {
    DIR_CENTER,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_SHOOT_DART,
    DIR_CHANGE_COLOR_DARK,
    DIR_CHANGE_COLOR_LIGHT,
    DIR_NORMAL_COLOR
} ACCEL_DIR_t;

/*
 * Initializes the Accelerometer/joystick on the M2K
 */
void accel_init(void);

/*
 * Used to start an ADC14 Conversion
 */
 void Task_Accelerometer_Timer(void *pvParameters);

 /*
  * Bottom Half Task. Examines the ADC data from the joystick on the M2K
  */
 void Task_Accelerometer(void *pvParameters);


#endif /* TASK_ACCELEROMETER_H_ */