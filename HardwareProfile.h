/* 
 * File:   HardwareProfile.h
 * Author: Dirk
 *
 * Created on August 10, 2013, 1:30 PM
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

/**Clock Defines*/
#define _XTAL_FREQ 4000000 //4MHz intrc for delay

/**I/O Defines*/
#define INPUT 1
#define OUTPUT 0
#define ON 1
#define OFF 0

#define LED_PIN PORTDbits.RD1
#define LED_TRIS TRISDbits.TRISD1

#define KEYPAD_ROW0_PORT TRISBbits.TRISB6
#define KEYPAD_ROW1_PORT TRISBbits.TRISB5
#define KEYPAD_ROW2_PORT TRISBbits.TRISB4
#define KEYPAD_ROW3_PORT TRISBbits.TRISB3

#define KEYPAD_COL0_PORT TRISBbits.TRISB2
#define KEYPAD_COL1_PORT TRISBbits.TRISB1
#define KEYPAD_COL2_PORT TRISBbits.TRISB0

#endif	/* HARDWAREPROFILE_H */

