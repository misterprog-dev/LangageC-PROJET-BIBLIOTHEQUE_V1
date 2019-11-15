#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

void AugmenterLivre(char *identifiant, int nombre){

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

    char requete[200],requete1[200];
    //On recupère le nombre de livre
    sprintf(requete,"SELECT nbreexemplaire FROM livre WHERE identifiant = '%s'",identifiant);

    if (mysql_query(con, requete)) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
  
    MYSQL_RES *result = mysql_store_result(con);
        
    if (result == NULL) 
    {
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    
    MYSQL_ROW row;
    row = mysql_fetch_row(result);
    long number = strtol(row[0],NULL,10);
    long total = nombre+number;

    sprintf(requete1,"UPDATE livre SET  nbreexemplaire = %ld  WHERE identifiant = '%s' ", total , identifiant);

    if(mysql_query(con,requete1)){
        fprintf(stderr, "%s\n", mysql_error(con));
        exit(1);
    }
    printf("\n\nAjout effectué avec succès !!!!\n");
    
    mysql_close(con);
}
