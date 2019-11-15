#include <my_global.h>
#include <mysql.h>

#ifndef DEF_EMPRUNT
#define DEF_EMPRUNT

void EmprunterLivre(char *numCE, char *identifiant);
void DepotLivre(char *numCE, char *identifiant);

#endif