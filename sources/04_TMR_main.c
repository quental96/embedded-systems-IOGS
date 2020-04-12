#include <xc.h>

#include "../resources/config.h"

void initPIC(void);

void main(void) {
    initPIC();
    while(1){
    }
    return;
}

void initPIC(void){
    ANSELA = 0;
    ANSELC = 0;
    TRISCbits.TRISC5 = 0;
    
    OSCCONbits.IRCF = 0b1100;
    
    OPTION_REGbits.PS = 0b010;     // Chapitre 18 - figure 18-1 - p. 137
    OPTION_REGbits.T0CS = 0;    // Chapitre 18 - registre 18-1 - p. 139
    OPTION_REGbits.PSA = 0;
    
    INTCONbits.TMR0IE = 1;  // Chapitre 7 - 7-1 - p. 64
    INTCONbits.GIE = 1;     // Chapitre 7 - 7-1 - p. 64
    return;
}

void interrupt prog_interruption(void){
    if(INTCONbits.TMR0IF == 1){      // Chapitre 7 - registre 7-1 - p. 64
        PORTCbits.RC5 = !PORTCbits.RC5;
        INTCONbits.TMR0IF = 0;
    }
}
