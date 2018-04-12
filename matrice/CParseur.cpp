#include "stdafx.h"
#include "CParseur.h"


CParseur::CParseur()
{
}

CParseur::CParseur(string sCheminFichier)
{
	cout << "Parseur init" << endl;
	ifPARFichier.open(sCheminFichier, ios::in);
	if (ifPARFichier)
	{
		string sLigne;
		unsigned int uiLigne = 0;
		unsigned int uiNbLignes = 0;
		unsigned int uiNbColonnes = 0;
		while (getline(ifPARFichier, sLigne))
		{
			if (sLigne.find("]") != -1) {
				break;
			}
			else {
				switch (uiLigne) {
				case 0:
					if (sLigne.find("double") == -1) {
						throw CException("La matrice dans le fichier n'est pas de type double");
					}
					break;
				case 1:
					sLigne = sLigne.substr(sLigne.find("=") + 1, sLigne.size());
					uiNbLignes = (unsigned int)std::stod(sLigne);
					break;
				case 2:
					sLigne = sLigne.substr(sLigne.find("=") + 1, sLigne.size());
					uiNbColonnes = (unsigned int)std::stod(sLigne);
					MATmatrice.MATSetDimensions(uiNbColonnes, uiNbLignes);
					break;
				case 3:
					break;
				default:
					char *pcEnd = new char[sLigne.length() + 1];
					strcpy_s(pcEnd, sLigne.length()+1,sLigne.c_str());
					for (unsigned int uiBoucle = 0; uiBoucle<uiNbColonnes; uiBoucle++) {
						double test = strtod(pcEnd, &pcEnd);
							MATmatrice.MATObtenirDonnees()[uiLigne - 4][uiBoucle] = test;
					}
					break;
				}
				uiLigne++;
			}
		}
		ifPARFichier.close();
	}
	else {
		throw CException("Impossible d'ouvrir le fichier");
	}
	cout << "Parseur fin" << endl;
}

CMatrice<double>& CParseur::PARGetMatrice()
{
	return MATmatrice;
}


CParseur::~CParseur()
{
}
