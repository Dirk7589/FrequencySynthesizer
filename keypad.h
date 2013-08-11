 /**
*@file keypad.h
*@author Dirk Dubois
*@date August 10th, 2013
*@brief A set of functions to interface with a 9 digit keypad
*/

#ifndef KEYPAD_H
#define	KEYPAD_H

#define ROW_0 PORTBbits.RB6
#define ROW_1 PORTBbits.RB5
#define ROW_2 PORTBbits.RB4
#define ROW_3 PORTBbits.RB3
#define COLUMN_0 PORTBbits.RB2
#define COLUMN_1 PORTBbits.RB1
#define COLUMN_2 PORTBbits.RB0

/**
*@brief Reads the value of the button being pushed
*@retval Button character in ASCII
*/
int keypadRead(char *value);


#endif	/* KEYPAD_H */

