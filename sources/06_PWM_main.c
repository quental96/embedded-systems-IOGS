#include <xc.h>
#include "config.h"

void changeDC1 (char val);
void initPWM1(void);

int res;

void changeDC1 (char val) {
    int temp = (val*4*(PR2+1))/100;
    PWM1DCL = temp << 6;
    PWM1DCH = temp >> 2;
}

void initPWM1 (void) {
    ANSELA = 0;
    ANSELC = 0;
    ANSELCbits.ANSC1 = 1;
    TRISCbits.TRISC1 = 1;
    
    ADCON0bits.CHS = 5;
    ADCON1bits.ADFM = 1;
    ADCON1bits.ADPREF = 0b00;
    ADCON1bits.ADCS = 0b011;
    ADCON0bits.ADON = 1;
    
    OSCCONbits.IRCF = 0b1100;
    
    TRISCbits.TRISC5 = 0;
    
    PWM1CONbits.PWM1EN = 1;
    PWM1CONbits.PWM1OE = 1;
    PWM1CONbits.PWM1POL = 0;
    
    PR2 = 31;
    changeDC1(0);
    T2CONbits.T2CKPS = 0b10;
    T2CONbits.TMR2ON = 1;
}

void main(void) {
    initPWM1();
    while(1){
        ADCON0bits.GO = 1;
        __delay_ms(100);
        res = ADRES * (100/1023);
        changeDC1(res);
    }
        
    return;
}

