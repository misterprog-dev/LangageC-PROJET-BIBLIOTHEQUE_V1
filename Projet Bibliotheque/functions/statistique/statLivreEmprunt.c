#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Python.h>
#include <my_global.h>
#include <mysql.h>

//ON REMPLIT LE FICHIER CSV D'ABORD AVANT D'APPELER PYTHON POUR LA STATISTIQUE

void StatLivreEmprunts(){
        //On supprime le fichier existant
        remove("file/statLivreEmprunt.csv");

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
        sprintf(requete,"SELECT identifiant FROM livre");

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
        fichier = fopen("file/statLivreEmprunt.csv", "a");
        if (fichier != NULL)
        { 
            fprintf(fichier,";nbreEmprunt;nbreDepot\n");
            while ((row = mysql_fetch_row(result))) 
            { 
                char m_requete[100];
                sprintf(m_requete,"SELECT COUNT(dateE),COUNT(dateD) FROM emprunt WHERE identifiant = '%s'",row[0]);
                if (mysql_query(con, m_requete)) 
                {
                    fprintf(stderr, "%s\n", mysql_error(con));
                    exit(1);
                }
                MYSQL_RES *resultR = mysql_store_result(con);
                
                if (resultR == NULL) 
                {
                    fprintf(stderr, "%s\n", mysql_error(con));
                    exit(1);
                }
                MYSQL_ROW rowR;
                rowR = mysql_fetch_row(resultR);
                long nbE = strtol(rowR[0],NULL,10);
                long nbD = strtol(rowR[1],NULL,10);

                fprintf(fichier,"%s;%ld;%ld\n",row[0],nbE,nbD);
            }
            fclose(fichier);
        }
        else
        {
            // On affiche un message d'erreur si on veut
            printf("Impossible d'ouvrir le fichier statLivreEmprunt.csv");
            
        }
      
        mysql_free_result(result);
        mysql_close(con);

        //////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////
        //On appel python ici

        Py_Initialize();
        PyRun_SimpleString("from pandas import read_csv");
        PyRun_SimpleString("import string");

        PyRun_SimpleString("dataEmp = read_csv(\"file/statLivreEmprunt.csv\",sep = \";\",header=0)");
        PyRun_SimpleString("summaryLivreEmp = dataEmp.describe()");
        PyRun_SimpleString("summaryLivreEmp = summaryLivreEmp.transpose()");

        PyRun_SimpleString("print summaryLivreEmp");

        //Py_Finalize();

        //////////////////////////////////////////////////////////////////////////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////


}