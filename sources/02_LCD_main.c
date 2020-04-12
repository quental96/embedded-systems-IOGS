#include <xc.h>
#include <stdio.h>

#include "../resources/config.h"
#include "../resources/spi.h"
#include "../resources/lcd.h"

void initPIC(void);

char ch[16] = "TP EITI 4";
int compteur = 0;
char cpt[16];
int oa=0;
int na;

void main(void) {
        
        initPIC();
        initLCD_DOG();
        clearLCD();
    
        writeCstStrLCD("IOGS ", 1, 1);
        __delay_ms(200);
    
        writeCstStrLCD("2 ", 1, 6);
        __delay_ms(200);
        writeCstStrLCD("0 ", 1, 8);
        __delay_ms(200);
        writeCstStrLCD("1 ", 1, 10);
        __delay_ms(200);
        writeCstStrLCD("8 ", 1, 12);

        writeStrLCD(ch, 2, 1);
        
        while(1){
            na=PORTAbits.RA2;
            if ((PORTAbits.RA2 == 1)&&(oa != PORTAbits.RA2)) {
                compteur+=1;
                __delay_ms(500);
            }
            oa=na;
            sprintf(cpt, "CPT = %d", compteur);
            writeStrLCD(cpt, 3, 1);
        } 
    return;
}

void initPIC(void){
    
    ANSELA = 0;
    ANSELC = 0;
    TRISAbits.TRISA2 = 1;
    
    OSCCONbits.IRCF = 0b1100;
    return;
}
