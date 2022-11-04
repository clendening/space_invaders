/*
 * task_spaceship.c
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */

#include <main.h>
#include <stdint.h>
#include <images.h>
#include <music.h>
#include "math.h"

QueueHandle_t Queue_Spaceship;
SemaphoreHandle_t Sem_LCD_Draw;
TaskHandle_t Task_Spaceship_Handle;
volatile uint16_t bugNum = 0;

/*
 * This function initializes Queue_Spaceship & Initializes the LCD
 */
void spaceship_init(void)
{

    // init the queue used to send SpaceShip commands
    Queue_Spaceship = xQueueCreate(3, sizeof(ACCEL_DIR_t));

    Crystalfontz128x128_Init();

    lcd_draw_rectangle(LCD_HORIZONTAL_MAX / 2, LCD_VERTICAL_MAX / 2,
    LCD_HORIZONTAL_MAX,
                       LCD_VERTICAL_MAX, LCD_COLOR_BLACK);
    lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 120, shipWidthPixels,
                   shipHeightPixels, shipBitmaps, LCD_COLOR_WHITE,
                   LCD_COLOR_BLACK);

}

volatile int spaceship_color = LCD_COLOR_WHITE;
/*
 * This task manages the movement of the spaceship. The ACCEL moves
 * the spaceship right or left.
 */
volatile uint8_t spaceshipX = LCD_HORIZONTAL_MAX / 2; // starting position in the middle of board
void Task_Spaceship(void *pvParameters)
{

    uint8_t prevX;
    uint8_t spaceshipY = 120; // starting position on bottom of LCD screen
    ACCEL_DIR_t dir;

    while (1)
    {

        // printf("TASK_SPACESHIP: ENTERED WHILE LOOP\n\r");
        // Wait until a command is sent to the queue
        xQueueReceive(Queue_Spaceship, &dir, portMAX_DELAY);
        xSemaphoreTake(Sem_LCD_Draw, portMAX_DELAY);
        //read the light sensor and change the color of the ship depending on the light level
        float luxVal = opt3001_read_lux();
        if (luxVal < 200.0)
        {
            spaceship_color = LCD_COLOR_RED;
        }
        else if (luxVal < 500.0)
        {
            spaceship_color = LCD_COLOR_WHITE;
        }
        else
        {
            spaceship_color = LCD_COLOR_GREEN;
        }
        //run this code if the message to shoot a dart has been received
        if (dir == DIR_SHOOT_DART)
        {

            //bugsLeft = bugsLeft - 1;
            //shoot the dart and see if it hit a bug
            dart_location = spaceshipX;
            BUTTON2_PRESSED = false;
            /*
             * depending on which bug is currently on the screen:
             * -change to the next bug
             * -check if the dart is overlapping with the bug
             *      -if it is: increment the score and play the bug hit sound effect
             *      -if it is not: play the missed sound effect
             */
            if (bugNum == 0)
            {
                bugNum = 1;
                // remove previous bug
                lcd_draw_image(50, 60, bug1WidthPixels, bug1HeightPixels,
                               bug1Bitmaps, LCD_COLOR_BLACK,
                               LCD_COLOR_BLACK);
                if ((dart_location >= 40) && (dart_location <= 60))
                {
                    score = score + 1;
                    hit_bug();
                }
                else
                {
                    missed_bug();
                }
            }
            else if (bugNum == 1)
            {
                bugNum = 2;
                // remove previous bug
                lcd_draw_image(90, 30, bug2WidthPages, bug2HeightPixels,
                               bug2Bitmaps, LCD_COLOR_BLACK,
                               LCD_COLOR_BLACK);
                if ((dart_location >= 80) && (dart_location <= 100))
                {
                    score = score + 1;
                    hit_bug();
                }
                else
                {
                    missed_bug();
                }

            }
            else if (bugNum == 2)
            {
                bugNum = 0;
                // remove previous bug
                lcd_draw_image(110, 10, bug3WidthPages, bug3HeightPixels,
                               bug3Bitmaps, LCD_COLOR_BLACK,
                               LCD_COLOR_BLACK);
                if ((dart_location >= 100) && (dart_location <= 120))
                {
                    score = score + 1;
                    hit_bug();
                }
                else
                {
                    missed_bug();
                }
            }
        }
        // Left Command
        if (dir == DIR_LEFT)
        {
            // boundary detection
            if (spaceshipX - 5 >= (shipWidthPixels / 2))
            {
                prevX = spaceshipX;
                // move spaceship in left direction
                spaceshipX = spaceshipX - 5;
            }
            // Right Command
        }
        else if (dir == DIR_RIGHT)
        {
            /* Boundary detection */
            if (spaceshipX + 5 <= (LCD_HORIZONTAL_MAX - (shipWidthPixels / 2)))
            {
                prevX = spaceshipX;
                // move spaceship in right direction
                spaceshipX = spaceshipX + 5;

            }
            // Center command
        }
        else if (dir == DIR_CENTER)
        {

        }

        /*
         * Draw Spaceship on LCD
         */

        if (prevX != spaceshipX)
        {
            // remove previous spaceship if spaceship has moved
            lcd_draw_image(prevX, spaceshipY, shipWidthPixels, shipHeightPixels,
                           shipBitmaps, LCD_COLOR_BLACK,
                           LCD_COLOR_BLACK);
            // draw new spaceship

            lcd_draw_image(spaceshipX, spaceshipY, shipWidthPixels,
                           shipHeightPixels, shipBitmaps, spaceship_color,
                           LCD_COLOR_BLACK);
        }

        if (bugNum == 0)
        {
            //draw new bug
            lcd_draw_image(50, 60, bug1WidthPixels, bug1HeightPixels,
                           bug1Bitmaps,
                           LCD_COLOR_MAGENTA,
                           LCD_COLOR_BLACK);
        }
        else if (bugNum == 1)
        {
            lcd_draw_image(90, 30, bug2WidthPages, bug2HeightPixels,
                           bug2Bitmaps,
                           LCD_COLOR_ORANGE,
                           LCD_COLOR_BLACK);
        }
        else if (bugNum == 2)
        {
            lcd_draw_image(110, 10, bug3WidthPages, bug3HeightPixels,
                           bug3Bitmaps,
                           LCD_COLOR_YELLOW,
                           LCD_COLOR_BLACK);
        }
        if (bugsLeft == 0)
        {
            while (1)
            {
                displayScore();
                vTaskDelay(20);
            }
        }
        // Release the semaphore back
        xSemaphoreGive(Sem_LCD_Draw);
        //  printf("TASK_SPACESHIP: spaceship drawn\n\r");

        // Task delay for delayMS
        // vTaskDelay(pdMS_TO_TICKS(5));

    }

}
/*
 * draw the number corresponding to the player's score and play the game over sound effect
 */
void displayScore(void)
{
    lcd_draw_rectangle(LCD_HORIZONTAL_MAX / 2, LCD_VERTICAL_MAX / 2,
    LCD_HORIZONTAL_MAX,
                       LCD_VERTICAL_MAX, LCD_COLOR_YELLOW);

    if (score == 0)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, zeroWidthPixels,
                       zeroHeightPixels, zeroBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 1)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, oneWidthPixels,
                       oneHeightPixels, oneBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 2)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, twoWidthPixels,
                       twoHeightPixels, twoBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 3)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, threeWidthPixels,
                       threeHeightPixels, threeBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 4)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, fourWidthPixels,
                       fourHeightPixels, fourBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 5)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, fiveWidthPixels,
                       fiveHeightPixels, fiveBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 6)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, sixWidthPixels,
                       sixHeightPixels, sixBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 7)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, sevenWidthPixels,
                       sevenHeightPixels, sevenBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 8)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, eightWidthPixels,
                       eightHeightPixels, eightBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    else if (score == 9)
    {
        lcd_draw_image(LCD_HORIZONTAL_MAX / 2, 70, nineWidthPixels,
                       nineHeightPixels, nineBitmaps, LCD_COLOR_RED,
                       LCD_COLOR_YELLOW);
    }
    game_over();
}
