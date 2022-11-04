/*
 * task_button.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Patron
 */

#ifndef TASK_BUTTON_H_
#define TASK_BUTTON_H_

#include <main.h>
extern TaskHandle_t Task_Button_Handle;
extern volatile uint16_t bugNum;
extern volatile uint8_t bugsLeft;
extern volatile uint8_t score;
extern volatile uint8_t dart_location;
volatile extern bool BUTTON2_PRESSED;

/****************************************************
 * initialize hardware resources used to control S2
 * on the MKII
 *****************************************************/
void ece353_MKII_S2_Init(void);

/*
 * Function configures Timer32_1 to generate a periodic interrupt every 10ms.
 */
void ece353_T32_1_Interrupt_Ms();

/*
 * This function initializes the button and sets the T32_1 interrupt every 10ms
 */
void button_init();

/*
 * bottom half of the button task. When it receives an interrupt from the ISR,
 * it will send a shoot command to Task_Dart
 */
void Task_Button_Bottom_Half();

/*
 *  IRQ Handler for T32_1. Sends a task notification to Task_Button_Bottom_Half
 * if S2 has been de-bounced and pressed. If S1 has been de-bounced it sets the
 * global variable which is used later in other tasks (mutually exclusive).
 */
void T32_INT1_IRQHandler();

#endif /* TASK_BUTTON_H_ */