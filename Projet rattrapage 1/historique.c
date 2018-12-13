//
// Created by Lars on 07/12/2018.
//
#include "historique.h"


void initCommande(Commande *historique, char nom[], char prenom[], char immatriculation[], int debut, int fin) {

    strcpy(historique->nom, nom);
    strcpy(historique->prenom, prenom);
    strcpy(historique->immatriculation, immatriculation);
    historique->debut = debut;
    historique->fin = fin;

}


int lireHistorique(Commande *historique) {
    int size = 0;

    historique = calloc(0, sizeof(Commande));

    FILE *fichier = NULL;
    fichier = fopen("D:\\utilisateur nyebo\\CLionProjects\\Projet rattrapage 1\\cmake-build-debug\\history.csv", "r");

    while (!feof(fichier)) {
        size++;

        historique = realloc(historique, size * sizeof(historique));
        fscanf(fichier, "%s;%s;%s;%d;%d", historique[size - 1].nom, historique[size - 1].prenom,
               historique[size - 1].immatriculation, &(historique[size - 1].debut), &(historique[size - 1].fin));
        fclose(fichier);


    }
    return size;

}

void entreeUtilisateur(Commande *commande) {


    printf("Entrez votre nom : ");
    scanf("%s\n", commande->nom);
    printf("prenom ");
    scanf("%s\n", commande->prenom);
    printf("nombre début de location :");
    scanf("%d\n", &(commande->debut));
    printf("fin de location :");
    scanf("%d\n", &(commande->fin));

}

bool moisValide() {
    enum Mois mois = 0, jour = 0;
    tempo *Date = 0;

    Date->jour = jour;
    Date->mois = mois;


    if (mois > 12 || mois < 1)
        return false;
    else
        return true;

}


bool jourValide() {

    enum Mois mois = 0, jour = 0;
    tempo *Date = 0;

    Date->jour = jour;
    Date->mois = mois;


    if (jour <= 0)
        return false;
    if (mois < JUILLET && mois % 2 == 0 && jour > 30)
        return false;
    if (mois == FEVRIER && jour > 29)
        return false;
    if ((mois == JUILLET || mois == AOUT) && jour > 31)
        return false;
    if (mois < JUILLET) {
        if ((mois % 2 == 0) && jour > 30)
            return false;
        if ((mois % 2 != 0) && jour > 31)
            return false;
    }
    if (mois > AOUT) {
        if ((mois % 2 == 0) && jour > 30)
            return false;
        if ((mois % 2 != 0) && jour > 31)
            return false;
    }
    return true;

}


void disponibilite() {

    enum Mois mois = 0, jour = 0;
    tempo *Date = 0;

    Date->jour = jour;
    Date->mois = mois;

    scanf("%d\n", &jour);
    scanf("%d\n", &mois);


}

int compDates(Date date1, Date date2) {

    if (date1.annee != date2.annee) {

        if (date1.annee > date2.annee)
            return SUPERIEUR;
        else if (date1.annee < date2.annee)
            return INFERIEUR;
        if (date1.mois )
        if (date1.jour > date2.jour)
            return SUPERIEUR;
        else if (date1.jour < date2.jour)
            if()


    }
}
