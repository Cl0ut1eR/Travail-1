#include "joueur.h"
Joueur::Joueur()
{
	nom = "";
	nombrevictoires = 0;
	nombreDefaites = 0;
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

void Joueur::Pointage(bool inVictoire)
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

#pragma endregion
