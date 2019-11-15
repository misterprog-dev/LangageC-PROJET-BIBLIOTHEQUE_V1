#include <my_global.h>
#include <mysql.h>

#ifndef DEF_ADHERENT
#define DEF_ADHERENT

void AjouterAdherent(char *numCE, char *nom, char *prenom, char* classe);
void AfficherTousAdherent();
int RechercherAdherent(char *numCE);
void AfficherAdherent(char *numCE);
void ModifierAdherent(char *numCE, char *nom, char *prenom, char *classe);
void SupprimerAdherent(char *numCE);

#endif