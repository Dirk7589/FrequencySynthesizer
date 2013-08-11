/**
 *@brief LCD interface example
*@date Feb. 9th, 2011
*@author Dirk Dubois
*@warning Uses routines from delay.c
 *	This code will interface to a standard LCD controller
 *	like the Hitachi HD44780. It uses it in 4 bit mode, with
 *	the hardware connected as follows (the standard 14 pin 
 *	LCD connector is used):
 *	
 *	PORTA bits 0-3 are connected to the LCD data bits 4-7 (high nibble)
 *	PORTA bit 4 is connected to the LCD RS input (register select)
 *  PORTA bit 6 is connected to the LCD RW input (register write)
 *	PORTA bit 7 is connected to the LCD EN bit (enable)
 *	
 *	To use these routines, set up the port I/O (TRISA, TRISD) then
 *	call lcd_init(), then other routines as required.
 */

#ifndef _XTAL_FREQ
 // Unless specified elsewhere, 4MHz system frequency is assumed
 #define _XTAL_FREQ 4000000
#endif

/*Includes*/
#include "lcd.h"
#include <xc.h>

/**
 * @brief
 * @param command
 */
void lcd_cmd(unsigned char command)
{
    LCD_RS = 0;
    LCD_EN = 0;
    LCD_DATA = ((command >>4) & 0x0F); //Send upper nibble

    LCD_STROBE();

    __delay_us(40); //Wait for controller to process instruction
    
    LCD_DATA = command & 0x0F; //Send lower nibble
    LCD_STROBE();

}

/**
*@brief Writes a byte to the LCD in 4-bit mode
*@param[in] char The byte to be written to the display
*@retval None
*/
void lcd_write(unsigned char c)
{
    LCD_DATA = ( (( c >> 4 ) & 0x0F) | (0xF0 & LCD_DATA));
    LCD_STROBE();
    LCD_DATA = ( (c & 0x0F)| (0xF0 & LCD_DATA));
    LCD_STROBE();
    __delay_us(40); //delay for a write operation
}

void lcd_cursor(char position)
{
    LCD_RS = 0;
    position = ((position & 0x7F) | 0x80) ;
    lcd_write(position);
}
/**
*@brief Clear and home the LCD
*@retval None
*/
void lcd_clear(void)
{
    LCD_RS = 0;
    lcd_write(0x1);
    __delay_ms(2);
}

/**
*@brief Write a string of characters to the LCD
*@param[in] s The char pointer to the characters to be written to the display
*@retval None
*/
void lcd_puts(const char * s)
{
    int count = 0;
    LCD_RS = 1;	// write characters

    while(*s && count < 16)
    {
        lcd_write(*s++);
        count++;
    }

    lcd_cursor(LINE_2_ADR);
    LCD_RS = 1;	// write characters
    
    while(*s)
    {
        lcd_write(*s++);
    }
}

/**
*@brief Writes a character to the LCD screen
*@param[in] char Writes the character to the screen
*@retval None
*/
void lcd_putch(char c)
{
    LCD_RS = 1;	// write characters
    lcd_write( c );
}

/**
*@brief Go to the specified position
*@param[in] pos Move the cursor to the position specified
*@retval None
*/
void lcd_goto(unsigned char pos)
{
    LCD_RS = 0;
    lcd_write(0x80+pos);
}
	
/**
*@brief Intialize the LCD
*@retval None
*@warning This function should be called before anything else
*/
void lcd_init()
{
    LCD_RS = 0;
    LCD_EN = 0;
    LCD_RW = 0;

    __delay_ms(500);
    
    LCD_DATA = 0x02; //Set 4 bit mode
    LCD_STROBE();
    __delay_us(40); //delay for function set operation

    lcd_cmd(0x28); //Set two line display
    lcd_cmd(0x0E); //Turn on cursor and display
    lcd_cmd(0x06); //Set mode to increment address by 1 to the right

    lcd_clear();
}
