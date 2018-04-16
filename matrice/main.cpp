#include "stdafx.h"
#include "CMatrice.h"
#include "CException.h"
#include "CParseur.h"

int main(char** argc, int argv)
{
	int iCoef;
	cout << "--- Matrice ---" << endl;
	cout << "Entrer un coefficient c : ";
	cin >> iCoef;
	vector<CMatrice<double>> vMatrice;

	try {
		for(unsigned int uiArg = 1; uiArg < (unsigned int)argv; uiArg++) {
			CParseur parser(argc[uiArg]);
			vMatrice.push_back(parser.PARGetMatrice());
		}

		CMatrice<double> MATtmp(vMatrice[0]);
		for (unsigned int uiBoucle = 1; uiBoucle < (unsigned int)(argv - 1); uiBoucle++) {
			MATtmp = MATtmp + vMatrice[uiBoucle];
		}

		MATtmp.MATAfficherMatrice();
		/*CParseur salut("C:/logs/matrice.txt");
		CMatrice<double> matfichier = salut.PARGetMatrice();
		(2*matfichier).MATAfficherMatrice();
		matfichier.MATTransposee().MATAfficherMatrice();
		cout << endl;*/
		
		/*
		CMatrice<double> coucou;
		coucou.MATInitMatrice();
		coucou.MATAfficherMatrice();
		CMatrice<double> coucou2;
		coucou2.MATInitMatrice();
		coucou2.MATAfficherMatrice();
		*/

		/*CMatrice<double> result = coucou / 2;
		CMatrice<double> result2 = coucou / 0;
		result.MATAfficherMatrice();
		result2.MATAfficherMatrice();*/
		/*matfichier = matfichier * matfichier;
		matfichier.MATAfficherMatrice();*/
	}
	catch (CException &EXCParam) {
		EXCParam.EXCAfficherMessage();
	}
    return 0;
}

