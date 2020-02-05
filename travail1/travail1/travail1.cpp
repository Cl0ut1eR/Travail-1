#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;

void InitialiserJoueurs();
void Jouer();

int main() 
{
	char fini = 'n';
	srand((unsigned)time(NULL));
	InitialiserJoueurs();
	while (fini=='n' || fini=='N')
	{
		Jouer();
		cout << "\nTermine (n/o) ? ";
		cin >> fini;	

	}
}

void Jouer() 
{
	int NombreDeCartesVoulue = -1;
	while (NombreDeCartesVoulue < (52/leJeu.GetNombreDeJoueurs) && NombreDeCartesVoulue < 0)
	{
		cout << "\nCombien de cartes voulez vous? \nMaximum " + std::to_string(52 / leJeu.GetNombreDeJoueurs());
		try
		{
			cin >> NombreDeCartesVoulue;
		}
		catch (const std::exception&)
		{
			cout << "\nVous devez entrer un nombre";
		}
	}



}

void InitialiserJoueurs()
{
	string NomTempo;
	for (int i = 0; i < leJeu.GetNombreDeJoueurs(); i++)
	{
		cout << "\nNom du joueur " + std::to_string(i+1);
		cin >> NomTempo;
		leJeu.TabDesJoueurs[i]->setNom(NomTempo);
	}
}
