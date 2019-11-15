#include <stdio.h>
#include <stdlib.h>

void Accueil(){

    printf("\n#################################################################");
    printf("\n################  BIENVENUE CHEZ ESATIC BIBLIO ##################");
    printf("\n#################################################################\n");

    //On vide nos fichiers csv qu demmarrage
    remove("file/statAdh.csv");
    remove("file/statLivreEmprunt.csv");
    remove("file/statLivre.csv");
}