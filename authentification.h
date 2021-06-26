struct utilisateur{
	int code;
	bool nifcin;
	char nif_cin[50];
	char[50] nom;
	char[50] prenom;
	char mot_de_passe[50];
	time_t date_de_creation;
	int type ;
	int etat_de_compte;
};

// Structure servant de base pour la lecture et l'ecriture des informations de base des utilisateur.