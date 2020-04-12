/*
 * Biblioth�que de fonctions pour l'utilisation de l'�cran LCD DOG EA 163
 * 3 x 16 caract�res en mode SPI - N�cessite la biblioth�que spi.h
 * A inclure dans les projets
 * #include "spi.h"
 * #include "lcd.h"
 */

#include "spi.h"

/* Ecran LCD */
#define RS_LCD   PORTAbits.RA0   // out

// LCD
/* 
 * Initialisation de l'�cran LCD 
 */
void initLCD_DOG(void);

/* 
 * Remise � z�ro de l'affichage sur l'�cran LCD 
 */
void clearLCD(void);

/* 
 * Envoi d'une commande � l'�cran LCD 
 *  entree : 
 *      - c : commande � transmettre
 */
void writeCmdLCD(char c);

/* 
 * Envoi d'un caract�re � afficher � la position du curseur sur l'�cran LCD 
 *  entree : 
 *      - c : caract�re � afficher
 */
void writeLCD(char c);

/* 
 * Envoi d'une chaine de caract�re � afficher 
 * � une position particuli�re sur l'�cran LCD 
 *  entrees : 
 *      - c[] : chaine de caract�re � afficher
 *      - ligne : ligne sur laquelle commencer l'affichage
 *      - colonne : colonne � partir de laquelle commencer l'affichage
 */
void writeStrLCD(char c[], char ligne, char colonne);

/* 
 * Envoi d'une chaine constante de caract�re � afficher 
 * � une position particuli�re sur l'�cran LCD 
 *  entrees : 
 *      - c[] : chaine de caract�re constante � afficher
 *      - ligne : ligne sur laquelle commencer l'affichage
 *      - colonne : colonne � partir de laquelle commencer l'affichage
 */
void writeCstStrLCD(const char c[], char ligne, char colonne);

/* 
 * Position du curseur sur l'�cran LCD
 *  entrees : 
 *      - ligne : ligne sur laquelle positionner le curseur
 *      - colonne : colonne sur laquelle positionner le curseur
 */
void setPosition(char ligne, char colonne);
