#include "donnees.h"
#include "..\screen\screen.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

Donnees leJeu;
CONSOLE_SCREEN_BUFFER_INFO ScreenInfo;

void InitialiserJoueurs();
void Jouer();
void DeciderNombreDeCartes();
void AttribuerCartes();
void AfficherCarte(Carte* uneCarte,int position);
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
	int CarteAffichee = 0;
	int TotalPionts = 0;
	cout << "\n\nMain de " + unJoueur->getNom()+"\n";
	for (int i = 0; i < leJeu.GetCartesEnMain(); i++)
	{
		AfficherCarte(unJoueur->GetCarte(i),i);
		TotalPionts += unJoueur->GetCarte(i)->GetValeur();
		CarteAffichee++;
		if (CarteAffichee == 3)
		{
			cout << "\n";
			CarteAffichee = 0;
		}
	}
	
	cout <<"\n\t"<< unJoueur->getNom()<< " a " << TotalPionts << " points\n";
}

void AfficherCarte(Carte* uneCarte,int inPosition = 0)
{

	/*switch (inPosition)
	{
	case 0:
		Gotoxy(15, ScreenInfo.dwCursorPosition.Y);
		break;
	case 1:
		Gotoxy(25, ScreenInfo.dwCursorPosition.Y);
		break;
	case 2:
		Gotoxy(35, ScreenInfo.dwCursorPosition.Y);
		break;
	}*/

	cout << "\t"<<std::to_string(uneCarte->GetValeur());

	/*switch (inPosition)
	{
	case 0:
		Gotoxy(17, ScreenInfo.dwCursorPosition.Y);
		break;
	case 1:
		Gotoxy(27, ScreenInfo.dwCursorPosition.Y);
		break;
	case 2:
		Gotoxy(37, ScreenInfo.dwCursorPosition.Y);
		break;
	}*/

	cout<<"\t"<<uneCarte->GetAtout();
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
