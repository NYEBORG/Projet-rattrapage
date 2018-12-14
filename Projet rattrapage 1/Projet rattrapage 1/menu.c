//
// Created by Lars on 05/12/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "voitures.h"
#include "menu.h"
#include "historique.h"

//Affiche le menu
void affich_menu() {
    printf("Bonjour et bienvenu au parc locatif, voulez-vous :\n"
           "1.Consulter l'historique des locations\n"
           "2.Louer un véhicule\n");
}


void choix_menu(Voiture *voitures) {
    int a = 0;
    Commande *historique =calloc(0, sizeof(Commande));
    Commande commande;

    bool continuer = false;
    do {
        scanf("%d", &a);

        while (getchar() != '\n');
        FILE *fichier = NULL;
        int size;
        switch (a) {
            case 1:
                //ouvrir l'historique

                size = lireHistorique(&historique);
                printHistorique(historique, size);

                continuer = false;
                break;
            case 2:

                entreeUtilisateur(&commande);
                int index = (int) ((rand() / (double) RAND_MAX) * 4);
                strcpy(commande.immatriculation, voitures[index].immatriculation);
                char stringDebut[255];
                char stringFin[255];

                printDate(&(commande.debut), stringDebut);
                printDate(&(commande.fin), stringFin);
                fichier = fopen(
                        "D:\\utilisateur nyebo\\CLionProjects\\Projet rattrapage 1\\cmake-build-debug\\history.csv",
                        "a");
                fprintf(fichier, "\n%s;%s;%s;%s;%s", commande.nom, commande.prenom, commande.immatriculation, stringDebut,
                        stringFin);

                fclose(fichier);


                continuer = false;
                break;


            default:
                printf("entrer le chiffre  1 ou 2");
                continuer = true;
                break;


        }
    } while (continuer);
}
