/*
 * Bibliothèque de fonctions pour la liaison SPI - PIC16F1509
 * A inclure dans les projets
 * #include "spi_1509.h"
 */


/* Liaison SPI */
#define SSPSS   PORTCbits.RC6   // out
#define SSPCK   PORTBbits.RB6   // out
#define SSPSDO  PORTCbits.RC7   // out

/* Fonctions */

/* 
 * Initialisation de la liaison SPI 
 *  entree : 
 *      - mode : mode de fonctionnement, entier compris entre 0 et 3
 */
void initSPI(char mode);

/* 
 * Envoi d'une donnee en SPI 
 *  entree : 
 *      - data : octet a envoyer
 */
void sendSPI(char data);
