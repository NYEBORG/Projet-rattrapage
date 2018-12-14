//
// Created by Lars on 05/12/2018.
//

#ifndef UNTITLED_VOITURES_H
#define UNTITLED_VOITURES_H


#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Structure de type voiture
typedef struct voiture Voiture;
struct voiture {
    char immatriculation[15];
    char marque[30];
    char modele[30];

};
// Initialisation de la voiture
void initVoiture(Voiture * maVoiture, char immatriculation[], char marque[], char modele[]);






#endif //UNTITLED_VOITURES_H
