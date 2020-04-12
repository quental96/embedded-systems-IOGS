#include <xc.h>
#include <stdio.h>

#include "../resources/config.h"
#include "../resources/spi.h"
#include "../resources/lcd.h"

int compteur;
char cpt[16];

void initPIC(void);

void main(void) {
    initPIC();
    initLCD_DOG();
    clearLCD();
    while(1){
        PORTCbits.RC3 = !PORTCbits.RC3;
        sprintf(cpt, "CPT = %d", compteur);
        writeStrLCD(cpt, 1, 1);
        __delay_ms(500);
    }
    return;
}

void initPIC(void){
    compteur = 0;
    ANSELA = 0;
    ANSELC = 0;
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC5 = 0;
    TRISAbits.TRISA2 = 1;
    TRISAbits.TRISA5 = 1;
    
    OSCCONbits.IRCF = 0b1100;
    
    IOCAP = 0;              // Chapitre 12 - registre 12-1 - p. 106 
    IOCAN = 0;              // Chapitre 12 - registre 12-2 - p. 106 
    IOCAPbits.IOCAP2 = 1;
    IOCANbits.IOCAN2 = 0;
    IOCAPbits.IOCAP5 = 1;
    IOCANbits.IOCAN5 = 0;
    
    INTCONbits.IOCIE = 1;   // Chapitre 7 - 7-1 - p. 64
    INTCONbits.GIE = 1;     
    return;
}

void interrupt prog_interruption(void){
    if(INTCONbits.IOCIF == 1){      // Chapitre 7 - registre 7-1 - p. 64
        if(IOCAFbits.IOCAF2 == 1){
            compteur+=1;
            __delay_ms(50);
            PORTCbits.RC5 = !PORTCbits.RC5;
            IOCAFbits.IOCAF2 = 0;            
                                    // Chapitre 12 - registre 12-3 - p. 106 
        }
        if(IOCAFbits.IOCAF5 == 1){
            compteur-=1;
            __delay_ms(50);
            IOCAFbits.IOCAF5 = 0;
        }
    }
}
