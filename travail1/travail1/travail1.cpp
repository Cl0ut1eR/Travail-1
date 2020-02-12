#include "donnees.h"
#include "..\screen\screen.h"
#include"Text.h"
#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
ClassText Texte = ClassText();

short AskNombreJoueurs();

Donnees leJeu = Donnees(AskNombreJoueurs());

void InitialiserJoueurs();
void Jouer();
void DeciderNombreDeCartes();
void AttribuerCartes();
void AfficherCarte(Carte* uneCarte);
void AfficherJoueur(Joueur* unJoueur , std::vector<std::string> nomGagnant);
void AfficherGagnants(std::vector<std::string> nomGagnant);
std::vector<std::string> TrouverGagnants();
int main() 
{
	TextColor(White);
	srand(unsigned(time(NULL)));

	char fini = 'n';
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
	std::vector<std::string> nomGagnant = TrouverGagnants();
	Texte.YActuel=0;
	Gotoxy(0, Texte.YActuel);
	ClrScr();
	cout << Texte.TextDeBase << Texte.InfoJoueurs;
	Texte.YActuel+=2;
	Gotoxy(Texte.XDefault, Texte.YActuel);
	for(int i=0;i<leJeu.GetNombreDeJoueurs();i++)
	{
		AfficherJoueur(leJeu.TabDesJoueurs[i], nomGagnant);
	}
	AfficherGagnants(nomGagnant);
}



short AskNombreJoueurs()
{
	short NombreDeJoueurs2 = 0;
	Gotoxy(0, 0);
	cout << Texte.TextDeBase;
	Texte.YActuel +=2;
	Gotoxy(Texte.XDefault, Texte.YActuel);
	cout << "Combien de joueurs etes vous?";
	Texte.YActuel ++;
	Gotoxy(Texte.XDefault, Texte.YActuel);
	while (!(std::cin >> NombreDeJoueurs2) || (NombreDeJoueurs2 > 52 || NombreDeJoueurs2 <= 0))
	{

		if (std::cin.fail())
		{
			ClrScr();
			cout << Texte.TextDeBase;
			Texte.YActuel = 2;
			Gotoxy(Texte.XDefault, Texte.YActuel);
			cout << "Vous devez entrer un nombre de joueurs";
			Texte.YActuel ++;
			Gotoxy(Texte.XDefault, Texte.YActuel);
			std::cin.clear();
			std::cin.ignore(2000, '\n');
		}
	}
	return NombreDeJoueurs2;
}

std::vector<std::string> TrouverGagnants()
{
	int PointageMax = -1;
	std::vector<std::string> TabGagnant;
	for (int i = 0; i < leJeu.GetNombreDeJoueurs(); i++)
	{
		if (leJeu.TabDesJoueurs[i]->GetPointageDeLaMain() > PointageMax)
		{
			PointageMax = leJeu.TabDesJoueurs[i]->GetPointageDeLaMain();
		}
	}
	for (int i = 0; i < leJeu.GetNombreDeJoueurs(); i++)
	{
		if (leJeu.TabDesJoueurs[i]->GetPointageDeLaMain() == PointageMax)
		{
			TabGagnant.push_back(leJeu.TabDesJoueurs[i]->getNom());
		}
	}
	return TabGagnant;
}

void AfficherGagnants(std::vector<std::string> nomGagnant)
{
	TextColor(Green);
	Texte.YActuel ++;
	Gotoxy(Texte.XDefault, Texte.YActuel);
	if (nomGagnant.size() == 1)
	{
		cout << "Le gagnant est :";
	}
	else
	{
		cout << "Les gagnants sont :";
	}
	Gotoxy(Texte.XDefault + 19, Texte.YActuel);
	for (int i = 0; i < nomGagnant.size(); i++)
	{
		cout << nomGagnant[i];
		Gotoxy(Texte.XDefault =+8, Texte.YActuel);
	}
	TextColor(White);
}

void AfficherJoueur(Joueur* unJoueur, std::vector<std::string> nomGagnant)
{
	TextColor(White);
	for (int i = 0; i < nomGagnant.size(); i++)
	{
		if (unJoueur->getNom() == nomGagnant[i])
		{
			TextColor(Green);
		}
	}
	int CarteAffichee = 0;
	Gotoxy(Texte.XDefault-2, Texte.YActuel);
	cout << "Main de " << unJoueur->getNom();
	Texte.YActuel++;
	Texte.XRendu = Texte.XDefault;
	Gotoxy(Texte.XRendu, Texte.YActuel);
	for (int i = 0; i < leJeu.GetCartesEnMain(); i++)
	{
		if (CarteAffichee == 0)
		{
			Texte.YActuel++;
			Texte.XRendu = Texte.XDefault;
			Gotoxy(Texte.XDefault, Texte.YActuel);
		}
		AfficherCarte(unJoueur->GetCarte(i));
		Texte.XRendu += 12;
		Gotoxy(Texte.XRendu, Texte.YActuel);
		CarteAffichee++;
		if (CarteAffichee == 4)
		{

			CarteAffichee = 0;
		}
	}
	Texte.YActuel++;
	Gotoxy(Texte.XDefault, Texte.YActuel);
	cout << unJoueur->getNom()<< " a " << unJoueur->GetPointageDeLaMain() << " points";
	Texte.YActuel+=2;
	Gotoxy(Texte.XDefault, Texte.YActuel);

	TextColor(White);
}

void AfficherCarte(Carte* uneCarte)
{
	cout <<std::to_string(uneCarte->GetValeur())<<" "<<uneCarte->GetAtout();
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
	ClrScr();
	Texte.YActuel=0;
	Gotoxy(0, Texte.YActuel);
	cout << Texte.TextDeBase<<Texte.InfoJoueurs;
	Texte.YActuel+=2;
	Gotoxy(Texte.XDefault, Texte.YActuel);
	cout << "Combien de cartes voulez vous?";
	Texte.YActuel++;
	Gotoxy(Texte.XDefault, Texte.YActuel);
	cout<<"Maximum " << std::to_string(52 / leJeu.GetNombreDeJoueurs());
	Texte.YActuel ++;
	Gotoxy(Texte.XDefault, Texte.YActuel);
	while (!(std::cin>> NombreDeCartesVoulue) || (NombreDeCartesVoulue > (52 / leJeu.GetNombreDeJoueurs()) || NombreDeCartesVoulue <= 0))
	{
		
		if (std::cin.fail())
		{
			ClrScr();
			Texte.YActuel=0;
			Gotoxy(0, Texte.YActuel);
			cout << Texte.TextDeBase << Texte.InfoJoueurs;
			Texte.YActuel +=2;
			Gotoxy(Texte.XDefault, Texte.YActuel);
			cout << "\nVous devez entrer un nombre";
			std::cin.clear();
			std::cin.ignore(2000, '\n');
		}
		Texte.YActuel += 2;
		Gotoxy(Texte.XDefault, Texte.YActuel);
		cout << "Combien de cartes voulez vous?" ;
		Texte.YActuel ++;
		Gotoxy(Texte.XDefault, Texte.YActuel); 
		cout<<"Maximum" << std::to_string(52 / leJeu.GetNombreDeJoueurs());
		Texte.YActuel ++;
		Gotoxy(Texte.XDefault, Texte.YActuel);
		
	}
	leJeu.SetCartesEnMain(NombreDeCartesVoulue);
}

void InitialiserJoueurs()
{
	std::string NomTempo="";
	for (int i = 0; i < leJeu.GetNombreDeJoueurs(); i++)
	{
		ClrScr();
		Texte.YActuel = 0;
		Gotoxy(0, Texte.YActuel);
		cout << Texte.TextDeBase << Texte.InfoJoueurs;
		Texte.YActuel +=2;
		Gotoxy(Texte.XDefault, Texte.YActuel);
		cout << "Nom du joueur " << std::to_string(i+1);
		Texte.YActuel ++ ;
		Gotoxy(Texte.XDefault, Texte.YActuel);
		cin >> NomTempo;
		leJeu.TabDesJoueurs.push_back(new Joueur);
		leJeu.TabDesJoueurs[i]->setNom(NomTempo);
		Texte.InfoJoueurs += "\t" +leJeu.TabDesJoueurs[i]->getNom() + " " + std::to_string( leJeu.TabDesJoueurs[i]->getVictoires());
	}
}
