/**
*@file lcd.h
*@brief LCD interface header file see lcd.c for more info
*@author Dirk Dubois
*@date Feb 12, 2011
*/

#ifndef __LCD_H
#define __LCD_H

/*I/O Port Defines*/
#define	LCD_RW PORTAbits.RA4
#define	LCD_RS PORTAbits.RA5
#define LCD_EN PORTAbits.RA7
#define LCD_DATA PORTA
#define LCD_PORT TRISA

/*Marco Defines*/
#define	LCD_STROBE()	((LCD_EN = 1),(NOP()),(NOP()), (LCD_EN = 0))

/*Controller Defines*/
#define LINE_1_ADR 0x00 //First line, left most position
#define LINE_2_ADR 0x40 //Second line, left most position

extern void lcd_cursor(char position);
/**
*@brief Clear and home the LCD
*@retval None
*/
extern void lcd_clear(void);

/**
*@brief Write a string of characters to the LCD
*@param[in] s The char pointer to the characters to be written to the display
*@retval None
*/
extern void lcd_puts(const char * s);

/**
*@brief Go to the specified position
*@param[in] pos Move the cursor to the position specified
*@retval None
*/
extern void lcd_goto(unsigned char pos);
	
/**
*@brief Intialize the LCD
*@retval None
*@warning This function should be called before anything else
*/
extern void lcd_init(void);

/**
*@brief Writes a character to the LCD screen
*@param[in] char Writes the character to the screen
*@retval None
*/
extern void lcd_putch(char);

#endif
