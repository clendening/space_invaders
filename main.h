/*
 * main.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */

#ifndef MAIN_H_
#define MAIN_H_


/* Necessary library includes */
#include "msp.h"
#include "msp432p401r.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* RTOS header files */
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/* Task Includes */
#include <task_accel.h>
#include <task_spaceship.h>
#include <task_button.h>
#include <opt3001.h>

/* Other Includes */
#include <images.h>
#include <lcd.h>
#include <music.h>

#endif /* MAIN_H_ */