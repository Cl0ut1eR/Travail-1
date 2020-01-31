#include <string>
#include "carte.h"
using namespace std;

#ifndef JoueurH
#define JoueurH

const int maxCartesAJouer = 26;
class Joueur
{


private:
	string nom;
	int nombrevictoires;
	int nombreDefaites;
	Carte* mainDuJoueur[maxCartesAJouer];


public:

	Joueur();
	Joueur(string nom, int nombreVictoires = 0, int nombreDefaites= 0);


	string getNom() const;
	int getVictoires() const;
	int getDefaites() const;

	void setNom(string Nom);

	void Pointage(bool Victoire);


	


};
#endif