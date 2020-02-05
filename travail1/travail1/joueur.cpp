#include "joueur.h"
Joueur::Joueur()
{
	nom = "";
	nombrevictoires = 0;
	nombreDefaites = 0;
	nombreDeCartesEnMain = 0;

	for (int i = 0; i < maxCartesAJouer;i++)
	{
		mainDuJoueur[i] = NULL;
	}
}

Joueur::Joueur(string inNom, int inNombreVictoires = 0, int inNombreDefaites = 0)
{
	nom = inNom;
	nombrevictoires= inNombreVictoires;
	nombreDefaites = inNombreDefaites;
	nombreDeCartesEnMain = 0;
	for (int i = 0; i < maxCartesAJouer; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}


#pragma region Get

string Joueur::getNom() const
{
	return nom;
}
int Joueur::getVictoires() const
{
	return nombrevictoires;
}
int Joueur::getDefaites() const
{
	return nombreDefaites;
}

#pragma endregion

#pragma region fonctions

void Joueur::setNom(string inNom)
{
	nom = inNom;
}

void Joueur::UpdatePointage(bool inVictoire)
{
	if (inVictoire)
	{
		nombrevictoires++;
	}
	else 
	{
		nombreDefaites++;
	}
}

void Joueur::AjouterUneCarte(Carte* inCarte)
{
	if (nombreDeCartesEnMain < 26)
	{
		mainDuJoueur[nombreDeCartesEnMain] = inCarte;
	}
}

void Joueur::RetirerCartes()
{
	for (int i = 0; i < nombreDeCartesEnMain; i++)
	{
		mainDuJoueur[i] = NULL;
	}
}

#pragma endregion
