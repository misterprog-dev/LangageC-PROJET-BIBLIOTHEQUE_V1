#include <my_global.h>
#include <mysql.h>

#ifndef DEF_LIVRE
#define DEF_LIVRE

void AjouterLivre(char *identifiant, char *nom, char *auteur, int nbexplaire);
void AfficherTousLivre();
void AfficherLivre(char *identifiant);
int RechercherLivre(char *identifiant);
void ModifierLivre(char *identifiant, char *nom, char *auteur);
void AugmenterLivre(char *identifiant, int nombre);
void SupprimerLivre(char *identifiant);

#endif