#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

void ModifierLivre(char *identifiant, char *nom, char *auteur){

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
    sprintf(requete,"UPDATE livre SET  nom = '%s' , auteur = '%s'  WHERE identifiant = '%s' ", nom, auteur, identifiant);

    if(mysql_query(con,requete)){
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    printf("\n\nLivre modifié avec succès !!!!\n");
 
    mysql_close(con);
}
