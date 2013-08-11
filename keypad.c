 /**
*@file keypad.c
*@author Dirk Dubois
*@date August 10th, 2013
*@brief A set of functions to interface with a 9 digit keypad
*/
#include "keypad.h"
#include <xc.h>

#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000
#endif

/**
*@brief Reads the value of the button being pushed

*/
int keypadRead(char *value)
{
    
    //read from column 0
    COLUMN_0 = 0;
    // Delay for debouncing
    __delay_ms(5);
    
    if(!ROW_0)
    {
        value[0] = '1';
        return 1;
    }
    if(!ROW_1)
    {
        value[0] = '4';
        return 1;
    }
    if(!ROW_2)
    {
        value[0] = '7';
        return 1;
    }
    if(!ROW_3)
    {
        value[0] = '*';
        return 1;
    }

    COLUMN_0 = 1;


    //read from column 1
    COLUMN_1  = 0;
    // Delay for debouncing
    __delay_ms(5);
    if(!ROW_0)
    {
        value[0] = '2';
        return 1;
    }
    if(!ROW_1)
    {
        value[0] = '5';
        return 1;
    }
    if(!ROW_2)
    {
        value[0] = '8';
        return 1;
    }
    if(!ROW_3)
    {
        value[0] = '0';
        return 1;
    }

    COLUMN_1 = 1;

 
    //read from column 2
    COLUMN_2 = 0;
    // Delay for debouncing
    __delay_ms(5);
    if(!ROW_0){
        value[0] = '3';
        return 1;
    }
    if(!ROW_1){
        value[0] = '6';
        return 1;
    }
    if(!ROW_2){
        value[0] = '9';
        return 1;
    }
    if(!ROW_3){
        value[0] = '#';
        return 1;
    }

    COLUMN_2 = 1;
    

    // Delay for debouncing
    __delay_ms(50);

    return 0;
}


