#include "donnees.h"


Donnees::Donnees(/*int inNombreDeJoueurs = 2*/)
{
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

void Donnees::MelangerCartes()
{
	//srand(time(NULL));
	int Case1 = 0;
	int Case2 = 0;
	for (int i = 0; i < 500; i++)
	{

	}
}

