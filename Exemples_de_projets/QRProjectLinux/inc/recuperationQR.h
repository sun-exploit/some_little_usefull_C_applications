#ifndef RECUPERATIONQR_H_INCLUDED
#define RECUPERATIONQR_H_INCLUDED

#include "saisie.h"

#define RESSOURCES_PATH "../ressources/"
#define RESSOURCES_PATH_LENGTH   17

char chemin[MAX_BUFFER_SIZE + RESSOURCES_PATH_LENGTH];
char nom_fichier[MAX_BUFFER_SIZE];

int init_tableau_QR();
int recuperation_QR();
int affich_tableau_QR();

int init_tableau_MASK_QR();
int recuperation_MASK_QR();
int application_MASK_QR();

#endif // RECUPERATIONQR_H_INCLUDED
