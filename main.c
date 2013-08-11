/* 
 * File:   main.c
 * Author: Dirk
 *
 * Created on August 10, 2013, 1:29 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include "HardwareProfile.h"
#include "lcd.h"
#include "keypad.h"

/**Config Bits*/
#pragma config CPD = OFF, BOREN = OFF
#pragma config IESO = OFF, DEBUG = OFF, FOSC = INTRC_NOCLKOUT, FCMEN = OFF
#pragma config MCLRE = OFF, WDTE = OFF, CP = OFF, LVP = OFF, PWRTE = OFF


/**Function Prototypes*/
int init(void);
void readInput(char *string);

/**
 * @brief The main function
 * @return EXIT_SUCCESS if correctly exited
 */
int main(void)
{
    init();
    lcd_init();
    char string[4];

    while(1)
    {
        readInput(string);
        lcd_putch(string[0]);
        lcd_putch(string[1]);
        lcd_putch(string[2]);
        lcd_putch(string[3]);
        //LED_PIN = ON;
       // __delay_ms(250);
       // LED_PIN = OFF;
       // __delay_ms(500);

        
        
    }
    return (EXIT_SUCCESS);
}

int init(void)
{
    OSCCON = 0x6F; //Set INTRC @ 4MHz

    /**Setup LCD Port*/
    LCD_PORT = 0x00;
    ANSEL = 0x00;
    

    /**Setup LED*/
    LED_TRIS = OUTPUT;
    LED_PIN = OFF;

    /**Setup Keypad*/
    

    KEYPAD_COL0_PORT = OUTPUT;
    KEYPAD_COL1_PORT = OUTPUT;
    KEYPAD_COL2_PORT = OUTPUT;

    KEYPAD_ROW0_PORT = INPUT;
    KEYPAD_ROW1_PORT = INPUT;
    KEYPAD_ROW2_PORT = INPUT;
    KEYPAD_ROW3_PORT = INPUT;

    ANSELH = 0x00;
    WPUB = 0b01111000;
    nRBPU = 0; //Ensure global pull ups enable
    IOCB = 0x00;

    COLUMN_0 = 1;
    COLUMN_1 = 1;
    COLUMN_2 = 1;

    return EXIT_SUCCESS;
}

void readInput(char *string)
{
    unsigned int count = 0;
    
    for(count = 0; count < 4; count++)
    {
        while(!keypadRead(string));
        __delay_ms(80);
        string++;
        
    }
}