include <stdio.h>
include <stdlib.h>
include <time.h>
include "authentification.h"

void save_user(){

	struct utilisateur* all_users;
	 FILE* fichier = NULL;

  time_t t = time(NULL);

	all_users->date_de_creation = *localtime(&t);

	fichier = fopen("UserData.txt", "w");

	if (fichier != NULL)
    	{
        	// On peut écrire dans le fichier

        printf("Veuillez entrer les information de l'utilisateur");

        printf("Le nom de l'utilisateur :");
        scanf("%s", &all_users->nom);

        printf("Le prenom de l'utilisateur :");
        scanf("%s", &all_users->prenom);

        printf("L'utilisateur a un NIF ou un CIN:");
        printf("NIF: 0\n CIN :1");
        scanf("%d", &all_users->nifcin);

        if ( all_users->nifcin==0)
        	{
		        printf("Veuillez enter le CIN de l'utilisateur :");
		        
	        }	
	     else if (all_users.nifcin==1)
	     	printf(" Veuillez enter le CIN de l'utilisateur");

	     scanf("%s", &all_users->nif_cin);

        printf("Le Mot de passe de l'utilisateur :");
        scanf("%s", &all_users->mot_de_passe);


        printf("Le type d'utilisateur:");

        printf(" L’administrateur : 0 \n fficiers de créditsJunior :1 \n  officiers de créditsSenior :2"\n);

        scanf("%d", &all_users->type);

 
        // On écrit les informations  dans le fichier
        fprintf(fichier, "%c %c %s %s %s %s %d %d %d %d %d " all_users->code, all_users->nifcin, all_users->nif_cin, all_users->nom, all_users->prenom, all_users->mot_de_passe, all_users->tm_mday, all_users->tm_mon + 1, all_users->tm_hour, tm.tm_min, all_users->type, all_users-> etat_de_compte);

    		fclose(fichier);
    	}

    else
    {
        printf("Impossible d'ouvrir le fichier UserData.txt");
    }

}