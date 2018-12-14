//
// Created by Lars on 05/12/2018.
//
#include "voitures.h"

//Crée une voiture avec immatriculation, marque et modèle
void initVoiture(Voiture *maVoiture, char immatriculation[], char marque[], char modele[]) {

    //Copie chaine de caractère dans une autre
    strcpy(maVoiture->immatriculation, immatriculation);
    strcpy(maVoiture->marque, marque);
    strcpy(maVoiture->modele, modele);



}





