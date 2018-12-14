#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "voitures.h"2
#include "menu.h"



int main() {
    //srand permet de définir une graine de génération(donnée permettant de générer un nmbre aléatoire ds ce cas )aléatoire pour nos futures utilisatiions de la fonction rand
    srand(time(NULL));
    //Définition des voitures
    Voiture voitures[4];
    initVoiture(&voitures[0], "CB-159-RX", "Lamborghini","Aventador");
    initVoiture(&voitures[1], "BX-422-PM", "Bugatti", "Veyron" );
    initVoiture(&voitures[2], "EK-018-MP", "Ferrari", "458 Spider GT");
    initVoiture(&voitures[3], "DS-389-EA","Maserati", "Granturismo");


    affich_menu();


    choix_menu(voitures);

    return 0;
}