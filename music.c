Switch to the Accessible Version of Box ›
All Files
Recents
Synced
Notes
Apps
Trash
My Collections

Favorites

Search Files and Folders





0

Company Logo

ece 353 project
task notifications work!
with light sensor




New

Share
NAME
UPDATED
SIZE



Sharing

Details
KAREENA CLENDENING
Owner

Samara Tabankin
Editor



Shared Link
Create Link


File Request
Create Link


v2
music.c
with light sensor
·
Updated May 2, 2022 by Samara Tabankin



Open
Download


Share
/*
 *music.c
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */
#include "music.h"
Note_t Our_Notes[] =
        { { NOTE_E6, ONE_HALF, true }, { NOTE_G6, ONE_HALF, true }, { NOTE_E7,ONE_HALF,true },
          { NOTE_C7, ONE_HALF, true }, { NOTE_D7, ONE_HALF, true }, { NOTE_G7,ONE_HALF, true }, {NOTE_G4, ONE_QUARTER, true}, {NOTE_G5, ONE_QUARTER, true}, {NOTE_G6, ONE_QUARTER, true}, {NOTE_E0, ONE_QUARTER, true}, {NOTE_D0, ONE_QUARTER, true}, {NOTE_C0, ONE_QUARTER, true}};
uint32_t music_get_time_delay(measure_time_t time)
{
    uint32_t time_return = 0;
    time_return = MEASURE_DURATION * MEASURE_RATIO;
    switch (time)
    {
    case ONE_QUARTER:
    {
        time_return = time_return / 4;
        break;
    }
    case ONE_HALF:
    {
        time_return = time_return / 2;
        break;
    }
    case ONE_EIGTH:
    {
        time_return = time_return / 8;
        break;
    }
    case THREE_EIGTH:
    {
        time_return = time_return * 3;
        time_return = time_return / 8;
        break;
    }
    default:
    {
        break;
    }
    }
    return time_return - DELAY_AMOUNT;
}
//***************************************************************************
// Plays a single note of the song based on note_index.  After
// the note is played, there is an optional delay in between
// notes.
//
// Examples
// Song[note_index].period       -- Used to determine the period of the
//                                  PWM pulse.
//
// Song[note_index].time         -- 1/4 or 1/2 time note.  Call
//                                  music_get_time_delay() to determine how
//                                  long to play the note
//
// Song[note_index].delay        -- If true, add a period of silence for
//                                  DELAY_AMOUNT
//
//                                  If false, return without delaying.
//*************************************************************************

static void music_play_note(uint16_t note_index)
{
    //initialize the PWM to the period of that note
    timerA_init(Our_Notes[note_index].period);
    //turn on the buzzer
    buzzer_on();
    //wait the duration of the note
    timer(music_get_time_delay(Our_Notes[note_index].time));
    //turn off the buzzer
    buzzer_off();
    //check to see if the note has a delay
    if (Our_Notes[note_index].delay == true)
    {
        //if it does wait the delay length
        timer(DELAY_AMOUNT);
    }
}
//***************************************************************
// Plays the song (loop through, playing each note)
// and then returns
//***************************************************************
void hit_bug(void)
{
  int i;
  for(i = 6; i<8; i++){
      music_play_note(i);
  }
}
void missed_bug(void)
{

          music_play_note(11);

}
void game_over(void)
{
    int i;
    for (i = 0; i < 6; i++)
    {
        music_play_note(i);
    }
}

void timerA_init(uint16_t ticks)
{
    //set 2.7 to a gpio pin
    P2->DIR |= BIT7;
    //select the primary function
    P2->SEL0 |= BIT7;
    P2->SEL1 &= ~BIT7;

    //turn of TA0
    TIMER_A0->CTL = 0;

    //set the period of the timer
    TIMER_A0->CCR[0] = ticks;

    //set duty cycle to 50%
    TIMER_A0->CCR[4] = (ticks / 2) - 1;
    //set the output mode to reset/set
    TIMER_A0->CCTL[4] = TIMER_A_CCTLN_OUTMOD_7;
    //set the source clock
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK;

}
void buzzer_on(void)
{
    //clear current mode
    TIMER_A0->CTL &= ~TIMER_A_CTL_MC_MASK;

    //set mode to up and clear current count
    TIMER_A0->CTL |= TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR;
}
void buzzer_off(void)
{
    //set the timer into stop mode to turn off the buzzer
    TIMER_A0->CTL &= ~TIMER_A_CTL_MC_MASK;
}
bool buzzer_status(void)
{
    //check if the mask on the timer is in stop mode and if it is return false meaning the buzzer is not on
    if ((TIMER_A0->CTL & TIMER_A_CTL_MC_MASK) == TIMER_A_CTL_MC__STOP)
    {
        return false;
    }
    //if it is not in stop mode return true meaning the buzzer is on
    else
    {
        return true;
    }
}
void timer(uint32_t ticks)
{
    //stop the timer
    TIMER32_2->CONTROL = 0;
    //set the timer to be a 32-bit one shot
    TIMER32_2->CONTROL = TIMER32_CONTROL_ONESHOT | TIMER32_CONTROL_SIZE;
    //set the load register
    TIMER32_2->LOAD = ticks;
    //start the timer
    TIMER32_2->CONTROL |= TIMER32_CONTROL_ENABLE;
    //wait until it reaches 0
    while (TIMER32_2->VALUE != 0)
    {
        //BUSY WAIT
    }
}