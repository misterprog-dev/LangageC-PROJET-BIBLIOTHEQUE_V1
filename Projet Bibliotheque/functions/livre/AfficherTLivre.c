#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <mysql.h>

void AfficherTousLivre(){

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

      if (mysql_query(con, "SELECT * FROM livre")) 
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
      MYSQL_FIELD *field;
      
      while ((row = mysql_fetch_row(result))) 
      { 
            int i=0;
            for( i = 0; i < num_fields; i++) 
            { 
                  if (i == 0) 
                        {              
                                while(field = mysql_fetch_field(result)) 
                                {
                                        printf("  ---  %s  ---", field->name);
                                }
                
                                printf("\n\n");           
                        }
                  printf("  ---  %s  ---", row[i] ? row[i] : "NULL"); 
            } 
            printf("\n"); 
      }
      
      mysql_free_result(result);
      mysql_close(con);
    
}
