#include "stdafx.h"
#include "CMatrice.h"
#include "CException.h"
#include "CParseur.h"

int main()
{

	CMatrice<double> MATtmp(vMatrice[0]);
	for (unsigned int uiCompteur = 1; uiCompteur < argv; i++) {
		if (uiCompteur % 2 == 0) {
			MATtmp[uiCompteur] += vMatrice[uiCompteur];
		}
		else {
			MATtmp[uiCompteur] -= vMatrice[uiCompteur];
		}

	}

	CMatrice<double> MATtmp(vMatrice[0]);
	for (unsigned int uiCompteur = 1; uiCompteur < argv; i++) {
		MATtmp[uiCompteur] *= vMatrice[uiCompteur];
	}
	/*
	try {
	
		CParseur salut("C:/logs/matrice.txt");
		CMatrice<double> matfichier = salut.PARGetMatrice();
		(2*matfichier).MATAfficherMatrice();
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
		result2.MATAfficherMatrice();
		matfichier = matfichier * matfichier;
		matfichier.MATAfficherMatrice();
	}
	catch (CException &EXCParam) {
		EXCParam.EXCAfficherMessage();
	}
	*/

    return 0;
}

