/*
 *opt3001.c
 *
 *  Created on: Apr 22, 2022
 *      Author: Kareena & Samara
 */

#include "opt3001.h"
#include "math.h"

/******************************************************************************
 * Initialize the opt3001 ambient light sensor on the MKII.  This function assumes
 * that the I2C interface has already been configured to operate at 100KHz.
 ******************************************************************************/

void opt3001_init(void)
{
    // Initialize OPT3001
    /* configuration register:
     * conversion time = 100 ms
     * continuous conversion
     */
    i2c_write_16(OPT3001_SLAVE_ADDRESS, CONFIG_REG, 0b1100010000010000);
}


/******************************************************************************
 * Returns the current ambient light in lux
 *  ******************************************************************************/
float opt3001_read_lux(void)
{
    // Read the Result register of OPT3001 and convert into Lux, then return.
    uint16_t recieved = i2c_read_16(OPT3001_SLAVE_ADDRESS, RESULT_REG);
    float lux = 0.01 * pow(2, recieved >> 12) *(recieved & 0b0000111111111111);

    return lux;

}





