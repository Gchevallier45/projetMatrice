#include "stdafx.h"
#include "CMatrice.h"
#include "CException.h"
#include "CParseur.h"

int main()
{
	cout << "--- Matrice des familles ---" << endl;
	try {
	
		CParseur salut("C:/logs/matrice.txt");
		CMatrice<double> matfichier = salut.PARGetMatrice();
		matfichier.MATAfficherMatrice();
		matfichier.MATTransposee().MATAfficherMatrice();
		cout << endl;
		
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
		matfichier = matfichier * matfichier;
		matfichier.MATAfficherMatrice();
	}
	catch (CException &EXCParam) {
		EXCParam.EXCAfficherMessage();
	}
    return 0;
}

