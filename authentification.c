#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>

#include "authentification.h"



void login(){
  int code;
  char password[50];

  struct utilisateur all_users;
do{
  printf("\n\n\n\t\t\tEntete du programme\n\n\n");
  printf("\t\t\t\tAcces\n\n");
  printf(" Code Utilisateur      :\n\n\n");


  scanf("%d", &code);


  if(login_check_ID(code, &all_users)==1)
    {
      printf("si vous etes %s %s, entrer votre mot de passe\n\n", all_users.prenom, all_users.nom);
      
      //system("clear");

      do
      {
      
      printf("\n\n\n\t\t\tEntete du programme\n\n\n");
      printf("\t\t\t\tAcces\n\n");
      printf(" Code Utilisateur      : %d     %s    %s \n\n\n", all_users.code, all_users.prenom, all_users.nom);
      printf(" Password      :\n\n\n");

      scanf("%s", password);

    
      
      if (!strcmp(password, all_users.mot_de_passe))
        
        {

          // Acces au menu

          menu_principal();


        }
      
      } while(strcmp(password, all_users.mot_de_passe));



    }

  else
    printf("ce compte n'existe pas");

}while(!login_check_ID(code, &all_users));

}



void save_user(){

	struct utilisateur all_users;

	FILE* fichier = NULL;

  time_t t = time(NULL);
	
  all_users.date_de_creation = localtime(&t);


	fichier = fopen("UserData.txt", "a+");


	if (fichier != NULL)
    	{
        char ligne[TAILLE_TABLEAU];

        all_users.code=0;

        
        while(fgets(ligne, TAILLE_TABLEAU , fichier)!=NULL)
        {
          if (sscanf(ligne,"%d %d %d %d %d %d %d %s %s %s %s", &all_users.code, &all_users.type, &all_users.etat_de_compte, &all_users.date_de_creation->tm_min, &all_users.date_de_creation->tm_hour, &all_users.date_de_creation->tm_mon, &all_users.date_de_creation->tm_year, all_users.nif_cin, all_users.nom, all_users.prenom, all_users.mot_de_passe)==11)
             
               printf("%d %d %d %d %d %d %d %s %s %s %s \n", all_users.code, all_users.type, all_users.etat_de_compte, all_users.date_de_creation->tm_min, all_users.date_de_creation->tm_hour, all_users.date_de_creation->tm_mon +1, all_users.date_de_creation->tm_year, all_users.nif_cin, all_users.nom, all_users.prenom, all_users.mot_de_passe);
        }
    

        all_users.code++;


        	// On peut écrire dans le fichier

     //fprintf(fichier,"%d",all_users->date_de_creation->tm_mday);
             

        printf("Veuillez entrer les information de l'utilisateur\n\n");

        printf("Le nom de l'utilisateur :\n");
        scanf("%s", all_users.nom);

        printf("Le prenom de l'utilisateur :\n");
        scanf("%s", all_users.prenom);

        printf("L'utilisateur a un NIF ou un CIN:\n");
        printf("NIF: 0              CIN :1\n");
        scanf("%d", &all_users.nifcin);

        if ( all_users.nifcin==0)
        	{
		        printf("Veuillez enter le CIN de l'utilisateur :\n");
		        
	        }	
	     else if (all_users.nifcin==1)
	     	printf(" Veuillez enter le CIN de l'utilisateur\n");

	     scanf("%s", all_users.nif_cin);

        printf("Le Mot de passe de l'utilisateur :\n");
        scanf("%s", all_users.mot_de_passe);


        printf("Le type d'utilisateur:\n");

        printf(" L’administrateur : 0     oficiers de crédits Junior :1     officiers de crédits Senior :2\n");

        scanf("%d", &all_users.type);

 
        all_users.etat_de_compte=1;

        // On écrit les informations  dans le fichier


     fprintf(fichier, "%d %d %d %d %d %d %d %s %s %s %s \n", all_users.code, all_users.type, all_users.etat_de_compte, all_users.date_de_creation->tm_min, all_users.date_de_creation->tm_hour, all_users.date_de_creation->tm_mon +1, all_users.date_de_creation->tm_year, all_users.nif_cin, all_users.nom, all_users.prenom, all_users.mot_de_passe);

      printf("l'utilisateur vient d'etre ajouter");
      }


    else
    {
        printf("Impossible d'ouvrir le fichier UserData.txt");
    }


}




int login_check_ID(int code, struct utilisateur* all_users){

  FILE* fichier = NULL;
  int val =0;

  fichier = fopen("UserData.txt", "r");


  if (fichier != NULL)
      {
        char ligne[TAILLE_TABLEAU];
        int tm_min, tm_hour, tm_mon, tm_year;
        
        while(fgets(ligne, TAILLE_TABLEAU , fichier)!=NULL)
        {
          

          if (sscanf(ligne,"%d %d %d %d %d %d %d %s %s %s %s", &all_users->code, &all_users->type, &all_users->etat_de_compte, &tm_min, &tm_hour, &tm_mon, &tm_year, all_users->nif_cin, all_users->nom, all_users->prenom, all_users->mot_de_passe)==11)
            if (code==all_users->code)
                {
                    val=1;
                    all_users->tm_min=tm_min;
                    all_users->tm_hour=tm_hour;
                    all_users->tm_mon=tm_mon;
                    all_users->tm_year=tm_year;
                   return 1;
                
                }
        }

        return val;

        


      }    
}



void menu_principal(){
  int choix1;

  do{
  //system("Clear screen");

  printf("\n\n\n\t\t\tEntete du programme\n\n\n");

  printf("\t\t\t\t Menu Principal\n\n\n");

  printf("1. Option 01 : Gestion des accès\n\n");
  printf("2. Option 02 : Gestion de crédits\n\n");
  printf("3. Option 03 : Administration et comptabilitén\n\n");
  printf("4. Option 04 : Quitter le programme\n\n"); 
  printf("\t\t\t\tFaites votre choix : [ 1, 2, 3, 4 ]\n") ; 

  scanf("%d", &choix1);

}while(choix1>4);


switch(choix1){
  case 1:   {
              menu_gestion_des_acces();
            }
    break;

  case 2: printf("Gestion des credits");
    break;

  case 3: printf(" Administration et comptabilite");
    break;

  case 4: printf(" Au revoir");
    break;

  }

}



void menu_gestion_des_acces(){
  int choix1;

  do{
  //system("clear");

  printf("\n\n\n\t\t\tEntete du programme\n\n\n");

  printf("\t\t\t\t Gestion des Acces\n\n\n");

  printf("1. Option 01 : Lister les utilisateurs\n\n");
  printf("2. Option 02 : Ajouter un utilisateur\n\n");
  printf("3. Option 03 : Modifier un utilisateur\n\n");
  printf("4. Option 04 : Quitter le programme\n\n"); 
  printf("\t\t\t\tFaites votre choix : [ 1, 2, 3, 4 ]\n") ; 

  scanf("%d", &choix1);

}while(choix1>4);


switch(choix1){
  case 1:   {
              afficher_user();
            }
    break;

  case 2: save_user();
    break;

  case 3: printf(" Administration et comptabilite");
    break;

  case 4: printf(" Au revoir");
    break;

  }

}



void afficher_user(){

struct utilisateur all_users;

  FILE* fichier = NULL;

  fichier = fopen("UserData.txt", "r");


  if (fichier != NULL)
      {
        char ligne[TAILLE_TABLEAU];
        int tm_min, tm_hour, tm_mon, tm_year;
        printf("code    NOM                  PRENOM               NIF/CIN\n");
        
        while(fgets(ligne, TAILLE_TABLEAU , fichier)!=NULL)
        {
          

          if (sscanf(ligne,"%d %d %d %d %d %d %d %s %s %s %s", &all_users.code, &all_users.type, &all_users.etat_de_compte, &tm_min, &tm_hour, &tm_mon, &tm_year, all_users.nif_cin, all_users.nom, all_users.prenom, all_users.mot_de_passe)==11)
              printf("%-7d %-20s %-20s %-20s\n", all_users.code, all_users.nom, all_users.prenom, all_users.nif_cin);
        }

  }
}