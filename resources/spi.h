/*
 * Bibliothèque de fonctions pour la liaison SPI - PIC16F1503
 * A inclure dans les projets
 * #include "spi.h"
 */


/* Liaison SPI */
#define SSPSS   PORTCbits.RC4   // out
#define SSPCK   PORTCbits.RC0   // out
#define SSPSDO  PORTCbits.RC2   // out

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
 *      - data : octet à envoyer
 */
void sendSPI(char data);
