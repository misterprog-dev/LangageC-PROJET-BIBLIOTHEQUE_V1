#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

void ModifierAdherent(char *numCE, char *nom, char *prenom, char *classe){

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
    sprintf(requete,"UPDATE adherent SET  nom = '%s' , prenom = '%s' , classe = '%s' WHERE numCE = '%s' ", nom, prenom, classe, numCE);

    if(mysql_query(con,requete)){
                fprintf(stderr, "%s\n", mysql_error(con));
                exit(1);
    }
    printf("\n\nAdhérent modifié avec succès !!!!\n");
    
    mysql_close(con);
}
