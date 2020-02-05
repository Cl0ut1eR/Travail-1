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
void DeciderNombreDeCartes();
void AttribuerCartes();
void AfficherCarte(Carte* uneCarte);
void AfficherJoueur(Joueur* unJoueur);

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
	
	DeciderNombreDeCartes();
	leJeu.MelangerCartes();
	AttribuerCartes();
	for(int i=0;i<leJeu.GetNombreDeJoueurs();i++)
	{
		AfficherJoueur(leJeu.TabDesJoueurs[i]);
	}
}

void AfficherJoueur(Joueur* unJoueur)
{
	int TotalPionts = 0;
	cout << "\n\nMain de " + unJoueur->getNom()+"\n";
	for (int i = 0; i < leJeu.GetCartesEnMain(); i++)
	{
		AfficherCarte(unJoueur->GetCarte(i));
		TotalPionts += unJoueur->GetCarte(i)->GetValeur();
	}
}

void AfficherCarte(Carte* uneCarte)
{
	cout << "\t"+std::to_string(uneCarte->GetValeur()) + "\t" + uneCarte->GetAtout();
}

void AttribuerCartes()
{
	int NombreDeCartesUtilisee = 0;
	for (int i = 0; i < leJeu.GetNombreDeJoueurs(); i++)
	{
		for(int j = 0; j < leJeu.GetCartesEnMain(); j++)
		{
			leJeu.TabDesJoueurs[i]->AjouterUneCarte(leJeu.TabDesCartes[NombreDeCartesUtilisee]);
			NombreDeCartesUtilisee++;
		}
	}

}

void DeciderNombreDeCartes()
{
	int NombreDeCartesVoulue = -1;

	cout << "\nCombien de cartes voulez vous? \nMaximum " + std::to_string(52 / leJeu.GetNombreDeJoueurs())+"\n";
	while (!(std::cin>> NombreDeCartesVoulue) || (NombreDeCartesVoulue > (52 / leJeu.GetNombreDeJoueurs()) || NombreDeCartesVoulue < 0))
	{
		
		if (std::cin.fail())
		{
			cout << "\nVous devez entrer un nombre";
			std::cin.clear();
			std::cin.ignore(2000, '\n');
		}
		cout << "\nCombien de cartes voulez vous? \nMaximum " + std::to_string(52 / leJeu.GetNombreDeJoueurs())+"\n";
		
	}
	leJeu.SetCartesEnMain(NombreDeCartesVoulue);
}

void InitialiserJoueurs()
{
	std::string NomTempo="";
	for (int i = 0; i < leJeu.GetNombreDeJoueurs(); i++)
	{
		cout << "\nNom du joueur " + std::to_string(i+1)+" ";
		cin >> NomTempo;
		leJeu.TabDesJoueurs[i] = new Joueur;
		leJeu.TabDesJoueurs[i]->setNom(NomTempo);
	}
}
