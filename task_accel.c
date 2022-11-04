/*
 * task_accelerometer.c
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */

#include <main.h>
#include <task_spaceship.h>

TaskHandle_t Task_Accelerometer_Handle;
TaskHandle_t Task_Accelerometer_Timer_Handle;

volatile uint32_t ACCEL_X_DIR = 0;

/*
 * Initializes the Accelerometer on the M2K
 */
void accel_init(void)
{    // Configure the X direction as an analog input pin.
    P4->SEL0 |= BIT0;
    P4->SEL1 |= BIT0;
    // Configure CTL0 to sample 16-times in pulsed sample mode.
    // Indicate that this is a sequence of samples.
    ADC14->CTL0 = ADC14_CTL0_SHP | ADC14_CTL0_SHT02;
    // Configure CTL1 to return 12-bit values
    ADC14->CTL1 = ADC14_CTL1_RES_2;
    // Set up the HI0 Window
    ADC14->HI0 = 2500;
    // Set up the LO0 Window
    ADC14->LO0 = 2000;
    // Associate the X direction analog signal with MEM[0], indicate the end of sequence, turn on the window comparator
    ADC14->MCTL[0] = ADC14_MCTLN_INCH_14;
    ADC14->MCTL[0] |= ADC14_MCTLN_EOS;
    ADC14->MCTL[0] |= ADC14_MCTLN_WINC;
    // Enable interrupts when either the HI or LO thresholds of the window comparator has been exceeded.  Disable all other interrupts
    ADC14->IER1 = ADC14_IER1_HIIE;
    ADC14->IER1 |= ADC14_IER1_LOIE;
    // Enable ADC Interrupt
    __enable_irq();
    NVIC_EnableIRQ(ADC14_IRQn);
    NVIC_SetPriority(ADC14_IRQn, 2);
    // Turn ADC ON
    ADC14->CTL0 |= ADC14_CTL0_ON;
}

/*
 * Used to start an ADC14 Conversion
 */
void Task_Accelerometer_Timer(void *pvParameters)
{
    while(1)
    {
        /*
         * Start the ADC conversion
         */
        ADC14->CTL0 |= ADC14_CTL0_SC | ADC14_CTL0_ENC;

        /*
         * Delay 5mS
         */
        vTaskDelay(pdMS_TO_TICKS(500));

    }
}

/******************************************************************************
 * Bottom Half Task.  Examines the ADC data from the accel on M2K
 ******************************************************************************/
void Task_Accelerometer(void *pvParameters)
{
    ACCEL_DIR_t dir;

    while (1)
    {
        /*
         * Wait until we get a task notification from the ADC14 ISR
         */
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
        char text[32];
        /*
         * Set the dir variable to one of the following values based
         * on the values of JOYSTICK_X_DIR and JOYSTIC_Y_DIR
         */
        if (ACCEL_X_DIR < 2000)
        {
            dir = DIR_LEFT;
            xQueueSend(Queue_Spaceship, &dir, portMAX_DELAY);
        }
        else if (ACCEL_X_DIR > 2150 )
        {
            dir = DIR_RIGHT;
            xQueueSend(Queue_Spaceship, &dir, portMAX_DELAY);
        }
        else
        {
            dir = DIR_CENTER;

            xQueueSend(Queue_Spaceship, &dir, portMAX_DELAY);
        }

        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

/*
 * Top Half of ADC14 Handler
 */
void ADC14_IRQHandler(void)
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // set the global variable that informs the application that the Window Comparator had detected a change
    // Determine if the HIIFG interrupt is active
        if (ADC14->IFGR1 & ADC14_IFGR1_HIIFG)
        {
    // Clear interrupt flag
            ADC14->CLRIFGR1 |= ADC14_CLRIFGR1_CLRHIIFG;
    // Turn off the HI interrupt
            ADC14->IER1 &= ~ADC14_IER1_HIIE;
    // Turn on LOW and IN interrupts
            ADC14->IER1 |= ADC14_IER1_LOIE;
            ADC14->IER1 |= ADC14_IER1_INIE;
            /*
                 * Send a task notification to Task_Joystick_Handle
                 */
                vTaskNotifyGiveFromISR(Task_Accelerometer_Handle, &xHigherPriorityTaskWoken);

                portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }
    // Determine if the LOIFG interrupt is active
        if (ADC14->IFGR1 & ADC14_IFGR1_LOIFG)
        {
    // Clear interrupt flag
            ADC14->CLRIFGR1 |= ADC14_CLRIFGR1_CLRLOIFG;
    // Turn off the LOW interrupt
            ADC14->IER1 &= ~ADC14_IER1_LOIE;
    // Turn on HI and IN interrupts
            ADC14->IER1 |= ADC14_IER1_HIIE;
            ADC14->IER1 |= ADC14_IER1_INIE;
            /*
                 * Send a task notification to Task_Joystick_Handle
                 */
                vTaskNotifyGiveFromISR(Task_Accelerometer_Handle, &xHigherPriorityTaskWoken);

                portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }
    // Determine if the INIFG interrupt is active
        if (ADC14->IFGR1 & ADC14_IFGR1_INIFG)
        {
    // Clear interrupt flag
            ADC14->CLRIFGR1 |= ADC14_CLRIFGR1_CLRLOIFG;
    // Turn off the IN interrupt
            ADC14->IER1 &= ~ADC14_IER1_INIE;
    // Turn on LOW and HI interrupts
            ADC14->IER1 |= ADC14_IER1_LOIE;
            ADC14->IER1 |= ADC14_IER1_HIIE;
            /*
                 * Send a task notification to Task_Joystick_Handle
                 */
                vTaskNotifyGiveFromISR(Task_Accelerometer_Handle, &xHigherPriorityTaskWoken);

                portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }

    ACCEL_X_DIR = ADC14->MEM[0]; // Read the value and clear the interrupt

}