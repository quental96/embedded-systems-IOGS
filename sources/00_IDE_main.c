#include "../resources/config.h"

void initPIC(void);

void main(void) {
    initPIC();
    while(1){
        PORTCbits.RC5 = PORTAbits.RA2 ;
        PORTCbits.RC3 = PORTAbits.RA5 ;
        __delay_ms(1000);
	}
    return;
}

void initPIC(void){
    ANSELA = 0x00;              // Chapitre 11 - Registre 11-5 - p. 99
    ANSELC = 0x00;              // Chapitre 11 - Registre 11-10 - p. 103
    TRISAbits.TRISA2 = 1;       // Chapitre 11 - Registre 11-3 - p. 98
    TRISCbits.TRISC5 = 0;       // Chapitre 11 - Registre 11-8 - p. 102
    TRISAbits.TRISA5 = 1;       // Chapitre 11 - Registre 11-3 - p. 98
    TRISCbits.TRISC3 = 0;
    
    OSCCONbits.IRCF = 0b1100;   // Chapitre 5 - Figure 5-1 - p. 43
                                // Chapitre 5 - Registre 5-1 - p. 49
    
    return;
}
