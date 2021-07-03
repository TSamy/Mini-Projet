#include <time.h>
#define TAILLE_TABLEAU 500

struct utilisateur{
    int code;
    int nifcin;
    char nif_cin[50];
    char nom[50];
    char prenom[50];
    char mot_de_passe[50];
    struct tm *date_de_creation;
    int tm_min;
    int tm_hour;
    int tm_mon;
    int tm_year;
    int type ;
    int etat_de_compte;
};

int login_check_PASSWORD(char mot1[50], char mot2[50]);
void save_user();
int login_check_ID(int code, struct utilisateur* all_users);
void menu_principal();
void menu_gestion_des_acces();
void afficher_user();
void login();
// Structure servant de base pour la lecture et l'ecriture des informations de base des utilisateur.