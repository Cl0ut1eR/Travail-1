#pragma once 
#include "Text.h"

ClassText::ClassText()
{
	TextDeBase = "Jeu de carte\t";
	InfoJoueurs = "";
	XDefault = 10;
	YActuel = 0;
	XRendu = 0;
}

void ClassText::UpdateScores(Donnees *leJeu)
{
	InfoJoueurs = "";
	for (int i = 0; i < leJeu->GetNombreDeJoueurs(); i++)
	{
		InfoJoueurs += "\t" + leJeu->TabDesJoueurs[i]->getNom() + " " + std::to_string(leJeu->TabDesJoueurs[i]->getVictoires());
	}

}