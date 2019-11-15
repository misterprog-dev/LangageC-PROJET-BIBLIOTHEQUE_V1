#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header/autre.h"
#include "header/adherent.h"
#include "header/emprunt.h"
#include "header/livre.h"
#include "header/stat.h"


int main(int argc, char **argv)
{
    int continuer = 0;
    do
    {
    system("clear");
    Accueil();
    Menu();
    int choix;
    do
    {
        printf("\tFaites votre choix :  ");
        scanf("%d", &choix);
    } while (choix<0 || choix>16 );

    //Connexion BD
    //InitiationConnexionMysql(con);

    char identifiant[40];
    char code[40];
    char nom[40];
    char auteur[40];
    int nbexplaire;
    char numCE[40];
    char prenom[40];
    char classe[40];

    switch (choix)
    {
        case 0:
            system("clear");
            printf("\n\nMerci !!!\n\n");
            exit(0);
            break;
        
        case 1:
            system("clear");
            printf("################ AFFICHAGE DE LIVRES ################\n\n");
            //Appel de la fonction affichage pour la BD
            AfficherTousLivre();
            printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
            scanf("%d", &continuer);
            break;
        case 2:
            system("clear");
            printf("################ AFFICHAGE D'UN LIVRE PARTICULIER ################\n\n");
            printf("Entrez le code du livre : ");
            lire(identifiant,40);
            lire(code,40);
            //On recherche le livre
            if(RechercherLivre(code) == 0){
                printf("\nCe code ne correspond à aucun livre !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {
                //Appel de la fonction affichage pour la BD
                printf("\n");
                AfficherLivre(code);
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }

            break;
        case 3:
            system("clear");
            printf("################ AJOUT DE LIVRE ################\n\n");
            printf("Entrez le code du livre : ");
            lire(identifiant,40);
            lire(code,40);
            printf("\nEntrez le nom du livre : ");
            lire(nom,40);
            printf("\nEntrez l'auteur du livre : ");
            lire(auteur,40);
            printf("\nEntrez le nombre d'exemplaire : ");
            scanf("%d", &nbexplaire);

            //Appel de la fonction ajout pour la BD

            AjouterLivre(code,nom,auteur,nbexplaire);
            printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
            scanf("%d", &continuer);

            break;
        case 4:
            system("clear");
            printf("################ MODIFICATION LIVRE ################\n\n");
            printf("Entrez le code du livre : ");
            lire(identifiant,40);
            lire(code,40);
            //On recherche le livre
            if(RechercherLivre(code) == 0){
                printf("\nCe code ne correspond à aucun livre !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {
                //S'il existe on rentre les nouveau nom
                printf("\nEntrez le nouveau nom du livre : ");
                lire(nom,40);
                printf("\nEntrez le nouveau nom de l'auteur du livre : ");
                lire(auteur,40);
                //Appel de l'upate
                ModifierLivre(code,nom,auteur);
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }

            break;
        case 5:
            system("clear");
            printf("################ AUGMENTER LIVRE ################\n\n");
            printf("Entrez le code du livre : ");
            lire(identifiant,40);
            lire(code,40);
            //On recherche le livre
            
             if( RechercherLivre(code) == 0){
                printf("\nCe code ne correspond à aucun livre !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {

                //Si le livre existe on retourne le nombre d'exemplaire
                int nbre;
                printf("\nEntrez le nombre d'exemplaire : ");
                scanf("%d", &nbre);
                //On ajoute
                AugmenterLivre(code, nbre);
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }
           
            break;
        case 6:
            system("clear");
            printf("################ SUPPRESSION D'UN LIVRE ################\n\n");
            printf("Entrez le code du livre : ");
            lire(identifiant,40);
            lire(code,40);
            //On recherche le livre
            if( RechercherLivre(code) == 0){
                printf("\nCe code ne correspond à aucun livre !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {
                SupprimerLivre(code);
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }

            break;
        case 7:
            printf("################ EMPRUNTER UN LIVRE ################\n\n");
            printf("Entrez le code du livre : ");
            lire(identifiant,40);
            lire(code,40);
            //On recherche le livre
            if(RechercherLivre(code) == 0){
                printf("\nCe code ne correspond à aucun livre !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {
                //Si le livre existe
                printf("Entrez le numéro étudiant de l'emprunteur : ");
                lire(numCE,40);
                //On recherche l'étudiant
                if(RechercherAdherent(numCE) == 0){
                    printf("\nCe code ne correspond à aucun adhérent !!!!\n");
                    printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                    scanf("%d", &continuer);
                }else
                {
                    EmprunterLivre(numCE, code);
                    printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                    scanf("%d", &continuer);
                }
            }

            break;
        case 8:
            printf("################ DEPOT DE LIVRE ################\n\n");
            printf("Entrez le code du livre : ");
            lire(identifiant,40);
            lire(code,40);
            //On recherche le livre
            if(RechercherLivre(code) == 0){
                printf("\nCe code ne correspond à aucun livre !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {
                //Si le livre existe
                printf("Entrez le numéro étudiant de l'emprunteur : ");
                lire(numCE,40);
                //On recherche l'étudiant
                if(RechercherAdherent(numCE) == 0){
                    printf("\nCe code ne correspond à aucun adhérent !!!!\n");
                    printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                    scanf("%d", &continuer);
                }else
                {
                    DepotLivre(numCE, code);
                    printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                    scanf("%d", &continuer);
                }
            }
            break;
        case 9:

            system("clear");
            printf("################ AFFICHAGE DES ADHERENTS ################\n\n");
            //Appel de la fonction affichage pour la BD
            AfficherTousAdherent();
            printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
            scanf("%d", &continuer);
            break;
        case 10:
            system("clear");
            printf("################ AFFICHAGE D'UN ADHERENT ################\n\n");
            printf("Entrez le numéro étudiant : ");
            lire(identifiant,40);
            lire(numCE,40);
            //On recherche l'étudiant
            //On recherche le livre
            if(RechercherAdherent(numCE) == 0){
                printf("\nCe code ne correspond à aucun adhérent !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {
                //Appel de la fonction affichage pour la BD
                printf("\n");
                AfficherAdherent(numCE);
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);

            }
            break;
        case 11:
            system("clear");
            printf("################ AJOUT D'UN ADHERENT ################\n\n");
            printf("Numéro CE : ");
            lire(identifiant,40);
            lire(numCE,40);
            printf("\nNom : ");
            lire(nom,40);
            printf("\nPrénom : ");
            lire(prenom,40);
            printf("\nClasse : ");
            lire(classe,40);
            //Appel de la fonction ajout pour la BD
            AjouterAdherent(numCE,nom,prenom,classe);
            printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
            scanf("%d", &continuer);

            break;
        case 12:
            system("clear");
            printf("################ MODIFICATION ADHERENT ################\n");
            printf("\nEntrez le numéro étudiant : ");
            lire(identifiant,40);
            lire(numCE,40);
            //On recherche l'étudiant
            if(RechercherAdherent(numCE) == 0){
                printf("\nCe code ne correspond à aucun adhérent !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {
                //S'il existe on rentre les nouveau nom
            
                printf("\nEntrez le nouveau nom : ");
                lire(nom,40);
                printf("\nEntrez le nouveau prénom : ");
                lire(prenom,40);
                printf("\nEntrez la nouvelle classe : ");
                lire(classe,40);
                //Appel de l'upate
                ModifierAdherent(numCE, nom, prenom, classe);
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);

            }
            break;
        case 13:
            system("clear");
            printf("################ SUPPRESSION D'UN ADHERENT ################\n");
            printf("\nEntrez le numéro étudiant : ");
            lire(identifiant,40);
            lire(numCE,40);
            //On recherche l'étudiant
            if(RechercherAdherent(numCE) == 0){
                printf("\nCe code ne correspond à aucun adhérent !!!!\n");
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }else
            {
                //Il existe on supprime
                SupprimerAdherent(numCE);
                printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
                scanf("%d", &continuer);
            }

            break;
        case 14:
            system("clear");
            printf("################ ZONE STATISTIQUE ################\n");
            //Zone stat
            printf("\n\n\t\tStatisque Adherents\n\n");
            StatAdherentEmprunts();
            printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
            scanf("%d", &continuer);
            break;
        case 15:
            system("clear");
            printf("################ ZONE STATISTIQUE ################\n");
            //Zone stat
            printf("\n\n\t\tStatisque Livres\n\n");
            StatLivres();
            printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
            scanf("%d", &continuer);

            break;
        case 16:
            system("clear");
            printf("################ ZONE STATISTIQUE ################\n");
            //Zone stat
            printf("\n\n\t\tStatisque Emprunt/Depots\n\n");
            StatLivreEmprunts();
            printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
            scanf("%d", &continuer);
            break;
    
        default:
            printf("\nAucun choix fait !!!!");
            printf("\n\tVoulez-vous revenir au menu principal ?  tapez : 0- non  1- oui  ");
            scanf("%d", &continuer);
            break;
    }
    printf("\n\n");

    } while (continuer != 0);

    return EXIT_SUCCESS;
}