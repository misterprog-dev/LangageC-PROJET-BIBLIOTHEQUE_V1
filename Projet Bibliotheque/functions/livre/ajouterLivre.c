#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

void AjouterLivre(char *identifiant, char *nom, char *auteur, int nbexplaire){

    MYSQL *con = mysql_init(NULL);
    if (con == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    if (mysql_real_connect(con, "localhost", "root", "", 
          "esaticbiblio", 0, NULL, 0) == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    
    char requete[200];
    sprintf(requete,"INSERT INTO livre VALUES ( '%s' , '%s' , '%s' , %d , NOW(),NULL )",identifiant, nom, auteur, nbexplaire);

    if(mysql_query(con,requete)){
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    printf("\n\nLivre ajouté avec succès !!!!\n");
    
    mysql_close(con);
}
