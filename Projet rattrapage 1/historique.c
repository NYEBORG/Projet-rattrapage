//
// Created by Lars on 07/12/2018.
//
#include "historique.h"

//Initialisation de la commande qui permet de rentrer
void initCommande(Commande *historique, char nom[], char prenom[], char immatriculation[], Date debut, Date fin) {

    strcpy(historique->nom, nom);
    strcpy(historique->prenom, prenom);
    strcpy(historique->immatriculation, immatriculation);
    historique->debut = debut;
    historique->fin = fin;

}

//Fonction qui lit l'historique
int lireHistorique(Commande *historique) {
    int size = 0;
    char stringDebut[255], stringFin[255], colonne[255];


    FILE *fichier = NULL;
    fichier = fopen("D:\\utilisateur nyebo\\CLionProjects\\Projet rattrapage 1\\cmake-build-debug\\history.csv", "r");
    fscanf(fichier, "%s", colonne);
    while (!feof(fichier)) {
        size++;

        historique = realloc(historique, size * sizeof(Commande));
        fscanf(fichier, "%[^';'|\]s;%[^';'|\]s;%[^';'|\]s;%[^';'|\]s;%[^';'|\]s", historique[size - 1].nom,
               historique[size - 1].prenom, historique[size - 1].immatriculation, stringDebut, stringFin);

        scanDate(&(historique[size - 1].debut), stringDebut);
        scanDate(&(historique[size - 1].fin), stringFin);

    }
    fclose(fichier);
    return size;

}


void entreeUtilisateur(Commande *commande) {

    char debut[255], fin[255];

    printf("Entrez votre nom : ");
    scanf("%s", commande->nom);
    printf("\nprenom");
    scanf("%s", commande->prenom);
    do {
        printf("\nDate début de location(jour/mois/année):");
        scanf("%s", debut);
        scanDate(&(commande->debut), debut);

    } while (!jourValide(commande->debut) && !moisValide(commande->debut));

    do {
        printf("\n2fin de location :");
        scanf("%s", fin);
        scanDate(&(commande->fin), fin);
    } while (!jourValide(commande->fin) && !moisValide(commande->fin));


}

bool moisValide(Date date) {
    int jour = date.jour;
    int mois = date.mois;


    if (mois > 12 || mois < 1)
        return false;
    else
        return true;

}


bool jourValide(Date date) {

    int jour = date.jour;
    int mois = date.mois;


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

void scanDate(Date *maDate,
              char *stringSource) {//string source contient la date sous le format jour/mois/année en chaîne de caractère. Lecture de stringSource et conversion en structure de type date.
    sscanf(stringSource, "%d/%d/%d", &(maDate->jour), &(maDate->mois), &(maDate->annee));
}

//sprintf fonctionne comme sscanf sauf qu'elle print
void printDate(Date *maDate, char *stringDest) {
    sprintf(stringDest, "%d/%d/%d", maDate->jour, maDate->mois, maDate->annee);
}

//Fonction qui compare les dates
int compDates(Date date1, Date date2) {

    if (date1.annee != date2.annee) {

        if (date1.annee > date2.annee)
            return SUPERIEUR;
        if (date1.annee < date2.annee)
            return INFERIEUR;
        if (date1.mois > date2.mois)
            return SUPERIEUR;
        if (date1.mois < date2.mois)
            return INFERIEUR;
        if (date1.jour > date2.jour)
            return SUPERIEUR;
        if (date1.jour < date2.jour)
            return INFERIEUR;
        if (date1.jour == date2.jour)
            return EGAL;

    }
}

//Print dans l'historique
void printHistorique(Commande *commande, int size) {

    for (int i = 0; i < size; i++) {
        char stringDebut[255], stringFin[255];

        printDate(&(commande->debut), stringDebut);
        printDate(&(commande->fin), stringFin);
        printf("%s;%s;%s;%s;%s", commande->nom, commande->prenom, commande->immatriculation, stringDebut, stringFin);
    }


};