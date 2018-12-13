//
// Created by Lars on 05/12/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "menu.h"
#include "voitures.h"
#include "historique.h"


void affich_menu() {
    printf("Bonjour et bienvenu au parc locatif, voulez-vous :\n"
           "1.Consulter l'historique des locations\n"
           "2.Louer un véhicule\n");
}


void choix_menu() {
    int a = 0;
    Commande *historique = NULL;

    bool continuer = false;
    do {
        scanf("%d", &a);

        while (getchar() != '\n');

        switch (a) {
            case 1:
                //ouvrir l'historique
                lireHistorique(historique);

                continuer = false;
                break;
            case 2:




                continuer = false;
                break;
            case 3:

            default:
                printf("entrer le chiffre  1 ou 2");
                continuer = true;
                break;



        }
    } while (continuer);
}
