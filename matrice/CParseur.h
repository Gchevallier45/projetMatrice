#ifndef CPARSEUR_H
#define CPARSEUR_H

#include <string>
#include <iostream>
#include <fstream>

#include "CException.h"
#include "CMatrice.h"

using namespace std;

class CParseur
{
	CMatrice<double> MATmatrice;
	ifstream ifPARFichier;
public:
	CParseur();
	CParseur(string sCheminFichier);
	CMatrice<double>& PARGetMatrice();
	~CParseur();
};

#endif //CPARSEUR_H