#pragma once
#include "carte.h"
#include "joueur.h"

const int maxCartes = 52;
const int NombreDeJoueurs=2;	


class Donnees
{
	
	private:

		void CreerCartes();
		int CartesEnMain;

	public:
		
		Donnees(/*int nombreDeJoueurs = 2*/);


		Joueur* TabDesJoueurs[NombreDeJoueurs];
		Carte* TabDesCartes[52];
		

		int GetCartesEnMain();
		int GetNombreDeJoueurs();
		void MelangerCartes();
		void SetCartesEnMain(int NombreDeCartes);


};

