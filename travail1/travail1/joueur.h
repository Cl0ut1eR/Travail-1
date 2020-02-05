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
	int nombreDeCartesEnMain;
	


public:

	Joueur();
	Joueur(string nom, int nombreVictoires, int nombreDefaites);


	string getNom() const;
	int getVictoires() const;
	int getDefaites() const;
	Carte* GetCarte(int Position);
	void setNom(string Nom);
	void UpdatePointage(bool Victoire);
	void AjouterUneCarte(Carte* Carte);
	void RetirerCartes();
	


};
#endif