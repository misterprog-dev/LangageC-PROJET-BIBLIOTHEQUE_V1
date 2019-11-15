#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

int RechercherAdherent(char *numCE){
        int nbre=0;
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
        char requete[100];
        sprintf(requete,"SELECT * FROM adherent WHERE numCE = '%s'",numCE);

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

        int num_fields = mysql_num_fields(result);

        MYSQL_ROW row;
        
        while ((row = mysql_fetch_row(result))) 
        { 
            nbre ++;
        }
      
        mysql_free_result(result);
        mysql_close(con);

        return nbre;  
}
