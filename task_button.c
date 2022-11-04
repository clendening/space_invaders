/*
 * task_button.c
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */

#include <main.h>
#include "task_spaceship.h"

TaskHandle_t Task_Button_Handle;
QueueHandle_t Queue_Spaceship;

/* Global variables to alert any tasks if button 1 or 2 has been pressed */
volatile extern bool BUTTON2_PRESSED = false;
volatile uint8_t dart_location = 0;

volatile uint8_t score = 0;
volatile uint8_t bugsLeft = 10;



/****************************************************
 * initialize hardware resources used to control S2
 * on the MKII
 *****************************************************/
void ece353_MKII_S2_Init(void)
{
    //configure as input
    P3->DIR &= ~BIT5;

    //enable resistor
    P3->REN |= BIT5;

    //resistor as a pull up
    P3->OUT |= BIT5;
}

/*
 * Function configures Timer32_1 to generate a periodic interrupt every 10ms.
 */
void ece353_T32_1_Interrupt_Ms()
{
    //ticks = desired period / core clock period
    //20e-3/(1/3e6) = (3e6 * 20)/1000
    uint32_t ticks = ((SystemCoreClock * 10) / 1000) - 1;

    //Stop the timer
    TIMER32_1->CONTROL = 0;

    // Set the load register
    TIMER32_1->LOAD = ticks;

    //Enable the Timer32 interrupt in NVIC
    __enable_irq();
    NVIC_EnableIRQ(T32_INT1_IRQn);
    NVIC_SetPriority(T32_INT1_IRQn, 2);

    //Start Timer32 and enable interrupt
    TIMER32_1->CONTROL = TIMER32_CONTROL_ENABLE |     // turn timer on
            TIMER32_CONTROL_MODE |       // periodic mode
            TIMER32_CONTROL_SIZE |       // 32 bit timer
            TIMER32_CONTROL_IE;          // enable interrupts

}

/*
 * This function initializes the button and sets the T32_1 interrupt every 10ms
 */
void button_init()
{

    // Initialize S2 on M2K
    ece353_MKII_S2_Init();

    /* Initialize the T32_1 to generate an interrupt every 10ms */
    ece353_T32_1_Interrupt_Ms();

}

/****************************************************
 * Returns if MKII.S2 is currently pressed
 *
 * Parameters
 *
 * Returns
 *      true    :       Button1 is pressed
 *      false   :       Button1 is not pressed
 *****************************************************/
bool ece353_MKII_S2(void)
{
    if ((P3->IN & BIT5 ) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * bottom half of the button task. When it receieves an interrupt from the ISR,
 * it will send a shoot command to Task_Spaceship
 */
void Task_Button_Bottom_Half(void *pvParameters)
{
ACCEL_DIR_t dir;
    BaseType_t status;
    while (1)
    {
        /* Wait until we get a task notification from the T32_INT1 ISR */
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    dir = DIR_SHOOT_DART;
    xQueueSend(Queue_Spaceship, &dir, portMAX_DELAY);


   BUTTON2_PRESSED = false;


        vTaskDelay(pdMS_TO_TICKS(5));
    }
}

/*
 *  IRQ Handler for T32_1. Sends a task notification to Task_Button_Bottom_Half
 * if S2 has been de-bounced and pressed. If S1 has been de-bounced it sets the
 * global variable which is used later in other tasks (mutually exclusive).
 */
void T32_INT1_IRQHandler()
{

    BaseType_t xHigherPriorityTaskWoken = pdTRUE;
    ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;
    if (!BUTTON2_PRESSED)
    {

        static uint8_t button2_state = 0x00;
        bool button2_pressed = ece353_MKII_S2();

        button2_state = button2_state << 1;

        if (button2_pressed)
        {

            button2_state |= 0x01;
        }

        /* 0111 1111 - Button has been pressed down for 70 consecutive ms */
        if (button2_state == 0x7F)
        {
            BUTTON2_PRESSED = true;
            //user has shot a dart so decrement the number of bugs left
            bugsLeft = bugsLeft - 1;
            /* Send a task notification to Task_Button_Bottom_Half */
            vTaskNotifyGiveFromISR(Task_Button_Handle,
                                   &xHigherPriorityTaskWoken);

            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);


        }
    }

    // clear the interrupt
    TIMER32_1->INTCLR = BIT0;

}