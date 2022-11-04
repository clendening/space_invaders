/*
 * task_spaceship.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */

#ifndef TASK_SPACESHIP_H_
#define TASK_SPACESHIP_H_

#include <main.h>

extern QueueHandle_t Queue_Spaceship;
extern SemaphoreHandle_t Sem_LCD_Draw;
extern TaskHandle_t Task_Spaceship_Handle;
extern volatile uint16_t bugNum;
extern volatile uint8_t spaceshipX;
#define BASE_DELAY 1


void spaceship_init(void);
void led_debug_init(void);
void led_debug(bool red_on, bool green_on, bool blue_on);
/*
 * This function initializes Queue_Spaceship & Initializes the LCD
 */
void spaceship_init(void);

/*
 * This task manages the movement of the spaceship. The joystick moves
 * the spaceship right or left.
 */
void Task_Spaceship(void *pvParameters);
/*
 * draw the number corresponding to the player's score and play the game over sound effect
 */
void displayScore(void);

#endif /* TASK_SPACESHIP_H_ */