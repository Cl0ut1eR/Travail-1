#pragma once
#include "carte.h"
#include "joueur.h"

#include <vector>

const short maxCartes = 52;


class Donnees
{
	
	private:

		void CreerCartes();
		int CartesEnMain;
		short NombreDeJoueurs;
	public:
		
		Donnees(short innombreDeJoueurs=2);


		//Joueur* TabDesJoueurs[NombreDeJoueurs];
		std::vector<Joueur*> TabDesJoueurs;
		
		Carte* TabDesCartes[maxCartes];
		

		int GetCartesEnMain();
		const int GetNombreDeJoueurs() const;
		int GetNombreDeCartes();
		void MelangerCartes();
		void SetCartesEnMain(int NombreDeCartes);


};

