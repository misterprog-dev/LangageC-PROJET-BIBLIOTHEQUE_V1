#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

void AjouterAdherent(char *numCE, char *nom, char *prenom, char* classe){

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
    sprintf(requete,"INSERT INTO adherent VALUES ( '%s' , '%s' , '%s' , '%s' , NOW(),NULL )",numCE, nom, prenom, classe);

    if(mysql_query(con,requete)){
                fprintf(stderr, "%s\n", mysql_error(con));
                exit(1);
    }
    printf("\n\nAdhérent ajouté avec succès !!!!\n");
    
    mysql_close(con);
}
