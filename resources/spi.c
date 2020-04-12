/*
 * Bibliothèque de fonctions pour la liaison SPI - PIC16F1503
 * A inclure dans les projets
 * #include "spi.h"
 */

#include <xc.h>
#include "spi.h"

/* 
 * Initialisation de la liaison SPI 
 *  entree : 
 *	- mode : mode de fonctionnement compris entre 0 et 3
 */
void initSPI(char mode){
    // INPUT / OUTPUT
    TRISCbits.TRISC4 = 0;   // SS
    TRISCbits.TRISC0 = 0;   // CK
    TRISCbits.TRISC2 = 0;   // SDO
    SSPSS = 1;
    
    // SSPxSTAT
    SSPSTATbits.SMP = 0;   // Input data sampled at middle of data output time
    SSPSTATbits.CKE = 0;   // Transmit occurs on transition from Idle to active clock state
    // SSPxCON1
    SSPCON1bits.CKP = 0;   // Idle state for clock is a low level
    SSPCON1bits.SSPEN = 1; // Enables serial port and configures SCKx, SDOx, SDIx and SSx as the source of the serial port pins
    SSPCON1bits.SSPM = 0b0000; // Synchronous Serial Port Mode Select bits - SPI Master mode, clock = F OSC /4
            // Avec FOSC = 16 MHz -> Vitesse de l'horloge = 4 MHz
    // SSPxCON2/3 - only for I2C
    return;
}

/* 
 * Envoi d'une donnee en SPI 
 *  entree : 
 * 	- data : octet a envoyer
 */
void sendSPI(char data){
    SSPBUF = data;
    while(!SSPSTATbits.BF); // Wait for Data Transmit/Receipt complete
    return;
}
