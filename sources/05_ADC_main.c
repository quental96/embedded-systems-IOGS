#include <xc.h>
#include <stdio.h>
#include "../resources/config.h"
#include "../resources/spi.h"
#include "../resources/lcd.h"

void initPIC(void);
void initADC( void );

int results;
char ch[16];

void main(void) {
    initPIC();
    initADC();
    initLCD_DOG();
    clearLCD();
    
    while(1){
        if (ADCON0bits.GO==0){
            results=ADRES*5/1023;
            clearLCD();
            sprintf(ch,"%d",results);
            writeStrLCD (ch,1,1);
            __delay_ms(100);
            ADCON0bits.GO=1;
        }
    }
    return;
}



void initPIC(void){
    
    ANSELA = 0;
    ANSELC = 0;
    OSCCONbits.IRCF = 0b1100;
    return;
}

void initADC( void ) {
	TRISCbits .TRISC1 = 1;
	ANSELCbits .ANSC1 = 1;

	ADCON0bits .CHS = 5;
	ADCON1bits .ADFM = 1;
	ADCON1bits .ADPREF = 0b00 ;
	ADCON1bits .ADCS = 0b011 ;
	ADCON0bits .ADON = 1;
}