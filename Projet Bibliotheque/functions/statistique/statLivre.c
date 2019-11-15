#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>
#include <my_global.h>
#include <mysql.h>

//ON REMPLIT LE FICHIER CSV D'ABORD AVANT D'APPELER PYTHON POUR LA STATISTIQUE

void StatLivres(){

        //On supprime le fichier existant
        remove("file/statLivre.csv");

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
        sprintf(requete,"SELECT identifiant, nbreexemplaire FROM livre");

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
        FILE* fichier = NULL;
        fichier = fopen("file/statLivre.csv", "a");
        if (fichier != NULL)
        {   
            fprintf(fichier,";nbreExemplaire\n");
            while ((row = mysql_fetch_row(result))) 
            { 
                long nbE = strtol(row[1],NULL,10);

                fprintf(fichier,"%s;%ld\n",row[0],nbE);
        
            }
            fclose(fichier);
        }
        else
        {
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier statLivre.csv");
            
        }
      
        mysql_free_result(result);
        mysql_close(con);

        //////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////
        //On appel python ici

        Py_Initialize();
        PyRun_SimpleString("from pandas import read_csv");
        PyRun_SimpleString("import string");

        PyRun_SimpleString("dataLivre = read_csv(\"file/statLivre.csv\",sep = \";\",header=0)");
        PyRun_SimpleString("summaryLivre = dataLivre.describe()");
        PyRun_SimpleString("summaryLivre = summaryLivre.transpose()");

        PyRun_SimpleString("print summaryLivre");

        //Py_Finalize();

        //////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////

}
