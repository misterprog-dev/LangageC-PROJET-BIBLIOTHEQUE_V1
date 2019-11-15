#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

void SupprimerLivre(char *identifiant){

    MYSQL *con = mysql_init(NULL);
    if (con == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);    }

    if (mysql_real_connect(con, "localhost", "root", "", 
          "esaticbiblio", 0, NULL, 0) == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }

    char requete[200];
    //On recupère le nombre de livre
    sprintf(requete,"DELETE FROM livre WHERE identifiant = '%s'",identifiant);

    if (mysql_query(con, requete)) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    printf("\n\nSuppression effectuée avec succès !!!!\n");

    mysql_close(con);
}
