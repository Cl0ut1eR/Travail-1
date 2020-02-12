#pragma once
#include <string>
#include "..\screen\screen.h"
#include <string>
#include <iostream>
#include"donnees.h"


using namespace std;

class ClassText
{
public:
	ClassText();
	std::string TextDeBase;
	std::string InfoJoueurs;
	short YActuel;
	short XDefault;
	short XRendu;

	void UpdateScores(Donnees *lejeu);
};

