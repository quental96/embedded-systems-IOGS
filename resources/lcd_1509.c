/*
 * Biblioth�que de fonctions pour l'utilisation de l'�cran LCD DOG EA 163
 * 3 x 16 caract�res en mode SPI
 * A inclure dans les projets
 * #include "lcd.h"
 */

#include <xc.h>
#include <stdio.h>
#include "config.h"
#include "spi_1509.h"
#include "lcd_1509.h"

/* 
 * Initialisation de l'�cran LCD 
 */
void initLCD_DOG(void){
    initSPI(0);
    TRISCbits.TRISC0 = 0;   // RS_LCD en sortie
    __delay_ms(10);
    SSPSS = 0;
    RS_LCD = 0;
    sendSPI(0x29);  // Function Set - table 1
    sendSPI(0x1D);  // Bias Set
    sendSPI(0x50);  // Power Control
    sendSPI(0x6C);  // Follower Control
    sendSPI(0x7C);  // Contrast Set
    sendSPI(0x03);  // Function Set - table 0
    sendSPI(0x0F);
    sendSPI(0x01);  // Clear Display
    __delay_ms(2);
    sendSPI(0x06);  // Display On
    __delay_ms(10);
    RS_LCD = 1;
    SSPSS = 1;
    __delay_ms(10);
    writeLCD('_');
    return;
}

/* 
 * Remise � z�ro de l'affichage sur l'�cran LCD 
 */
void clearLCD(void){
    SSPSS = 0;
    RS_LCD = 0;
    writeCmdLCD(0x01);    // Clear Display
    __delay_ms(2);        // delay 2 ms
    RS_LCD = 1;
    SSPSS = 1;    
    return;
}

/* 
 * Envoi d'une commande � l'�cran LCD 
 *  entree : 
 *      - c : commande � transmettre
 */
void writeCmdLCD(char c){
    SSPSS = 0;
    RS_LCD = 0;
    sendSPI(c);
    __delay_ms(1);   
    RS_LCD = 1;
    SSPSS = 1; 
    return;
}

/* 
 * Envoi d'un caract�re � afficher � la position du curseur sur l'�cran LCD 
 *  entree : 
 *      - c : caract�re � afficher
 */
void writeLCD(char c){
    SSPSS = 0;
    RS_LCD = 1;
    sendSPI(c);
    __delay_ms(1);
    SSPSS = 1;
    return;
}

/* 
 * Envoi d'une chaine de caract�re � afficher 
 * � une position particuli�re sur l'�cran LCD 
 *  entrees : 
 *      - c[] : chaine de caract�re � afficher
 *      - ligne : ligne sur laquelle commencer l'affichage
 *      - colonne : colonne � partir de laquelle commencer l'affichage
 */
void writeStrLCD(char c[], char ligne, char colonne){
    char i = 0;
    setPosition(ligne, colonne);
    while(c[i] != '\0'){
        writeLCD(c[i]);
        i++;
    }
    return;
}

/* 
 * Envoi d'une chaine constante de caract�re � afficher 
 * � une position particuli�re sur l'�cran LCD 
 *  entrees : 
 *      - c[] : chaine de caract�re constante � afficher
 *      - ligne : ligne sur laquelle commencer l'affichage
 *      - colonne : colonne � partir de laquelle commencer l'affichage
 */
void writeCstStrLCD(const char c[], char ligne, char colonne){
    char i = 0;
    setPosition(ligne, colonne);
    while(c[i] != '\0'){
        writeLCD(c[i]);
        i++;
    }
    return;
}

/* 
 * Position du curseur sur l'�cran LCD
 *  entrees : 
 *      - ligne : ligne sur laquelle positionner le curseur
 *      - colonne : colonne sur laquelle positionner le curseur
 */
void setPosition(char ligne, char colonne){
    char adress = 0x80 + ((ligne-1) * 16) + (colonne - 1);
    writeCmdLCD(adress);
    __delay_ms(1);
    return;
}
