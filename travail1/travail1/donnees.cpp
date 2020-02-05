#include "donnees.h"
#include<time.h>

Donnees::Donnees(/*int inNombreDeJoueurs = 2*/)
{
	CartesEnMain = 0;
	/*NombreDeJoueurs = inNombreDeJoueurs;*/
	CreerCartes();
}


void Donnees::CreerCartes()
{
	int CptCartes = 1;
	int CptAtout = 0;
	string TabAtout[4] = {"pique", "coeur", "trefle", "carreau" };
	for (int i = 0; i < 51; i++)//pique, coeur, trèfle ou carreau
	{
		TabDesCartes[i] = new Carte;
		TabDesCartes[i]->InitialiserCarte(CptCartes, TabAtout[CptAtout]);
		CptCartes++;
		if (CptCartes > 13)
		{
			CptCartes = 1;
			CptAtout++;
		}
	}
}

int Donnees::GetNombreDeJoueurs()
{
	return NombreDeJoueurs;
}

int Donnees::GetCartesEnMain()
{
	return CartesEnMain;
}

void Donnees::SetCartesEnMain(int inNombreDeCartes = (52/NombreDeJoueurs))
{
	CartesEnMain = inNombreDeCartes;
}

void Donnees::MelangerCartes()
{
	srand(time(NULL));	Carte* CarteTempo = NULL;
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

