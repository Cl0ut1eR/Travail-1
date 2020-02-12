#include "donnees.h"
#include<time.h>

Donnees::Donnees(short inNombreDeJoueurs)
{
	CartesEnMain = 0;
	NombreDeJoueurs = inNombreDeJoueurs;
	CreerCartes();
}


void Donnees::CreerCartes()
{
	int CptCartes = 1;
	int CptAtout = 0;
	string TabAtout[4] = {"pique", "coeur", "trefle", "carreau" };
	for (int i = 0; i < maxCartes; i++)//pique, coeur, trèfle ou carreau
	{
		TabDesCartes[i] = new Carte;
		TabDesCartes[i]->InitialiserCarte(CptCartes, TabAtout[CptAtout]);
		CptCartes++;
		if (CptCartes > (maxCartes/4))
		{
			CptCartes = 1;
			CptAtout++;
		}
	}
}

const int Donnees::GetNombreDeJoueurs() const
{
	return NombreDeJoueurs;
}

int Donnees::GetNombreDeCartes()
{
	return maxCartes;

}


int Donnees::GetCartesEnMain()
{
	return CartesEnMain;
}

void Donnees::SetCartesEnMain(int inNombreDeCartes)
{
	CartesEnMain = inNombreDeCartes;
}

void Donnees::MelangerCartes()
{	Carte* CarteTempo = NULL;
	int Case1 = 0;
	int Case2 = 0;
	for (int i = 0; i < 500; i++)
	{
		Case1 = (0 + (rand() % 51));
		Case2 = (0 + (rand() % 51));
		CarteTempo			= TabDesCartes[Case1];
		TabDesCartes[Case1]	= TabDesCartes[Case2];
		TabDesCartes[Case2] = CarteTempo;
	}
}

