//
// Created by Lars on 07/12/2018.
//

#ifndef UNTITLED_HISTORIQUE_H
#define UNTITLED_HISTORIQUE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct date Date;
struct date{
    int jour;
    int mois;
    int annee;
};

int compDates(Date date1,Date date2);

enum { INFERIEUR, EGAL, SUPERIEUR };

enum Mois { JANVIER=1, FEVRIER, MARS, AVRIL, MAI, JUIN, JUILLET, AOUT, SEPTEMBRE, OCTOBRE, NOVEMBRE, DECEMBRE};

typedef struct commande Commande;
struct commande{
char nom[50];
char prenom[50];
char immatriculation[15];
Date debut;
Date fin;
};

int lireHistorique( Commande* historique);

void entreeUtilisateur(Commande * commande);

bool moisValide();
bool jourValide();


void scanDate(Date * maDate, char * stringSource);
void printDate(Date *maDate,char *stringDest);


void printHistorique(Commande * commande, int size);

void initCommande(Commande * historique, char nom[], char prenom[], char immatriculation[], Date debut, Date fin);


void disponibilite();

#endif //UNTITLED_HISTORIQUE_H
