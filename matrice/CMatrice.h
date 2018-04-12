#ifndef CMATRICE_H
#define CMATRICE_H

#include <iostream>
#include "CException.h"

using namespace std;

template <class Type> class CMatrice
{
	Type** ptMATmatrice;
	unsigned int uiMATcolonnes;
	unsigned int uiMATlignes;

public:
	CMatrice();
	CMatrice(CMatrice &MATParam);
	CMatrice<Type>& operator / (double dParam);
	CMatrice<Type>& operator = (CMatrice &MATParam);
	CMatrice<Type>& operator - (CMatrice &MATParam);
	CMatrice<Type>& operator * (double);
	CMatrice<Type>& operator * (CMatrice<Type> &);
	CMatrice<Type>& operator + (CMatrice<Type> &);
	Type ** MATObtenirDonnees();
	void MATAfficherMatrice();
	void MATInitMatrice();
	void MATSetDimensions(unsigned int uiColonnes,unsigned int uiLignes);
	unsigned int MATObtenirColonnes();
	unsigned int MATObtenirLignes();
	~CMatrice();
};

template<class Type> CMatrice<Type>::CMatrice()
{
	uiMATlignes = 0;
	uiMATcolonnes = 0;
	ptMATmatrice = NULL;
}

template<class Type> CMatrice<Type>::CMatrice(CMatrice & MATParam)
	:uiMATcolonnes(MATParam.uiMATcolonnes), uiMATlignes(MATParam.uiMATlignes)
{
	ptMATmatrice = new Type*[uiMATlignes];
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		ptMATmatrice[uiLigne] = new Type[uiMATcolonnes];
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			ptMATmatrice[uiLigne][uiColonne] = MATParam.ptMATmatrice[uiLigne][uiColonne];
		}
	}
}

template<class Type> void CMatrice<Type>::MATInitMatrice() {
	cin >> uiMATlignes;
	cin >> uiMATcolonnes;
	ptMATmatrice = new Type*[uiMATlignes];
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		ptMATmatrice[uiLigne] = new Type[uiMATcolonnes];
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			cin >> ptMATmatrice[uiLigne][uiColonne];
		}
	}
}

template<class Type> void CMatrice<Type>::MATSetDimensions(unsigned int uiColonnes, unsigned int uiLignes)
{
	if (uiColonnes != 0 && uiLignes != 0) {
		if (uiMATcolonnes != 0 && uiMATlignes != 0) {
			for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
				delete[] ptMATmatrice[uiLigne];
			}
			delete[] ptMATmatrice;
		}
		uiMATcolonnes = uiColonnes;
		uiMATlignes = uiLignes;
		ptMATmatrice = new Type*[uiMATlignes];
		for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
			ptMATmatrice[uiLigne] = new Type[uiMATcolonnes];
		}
	}
	else {
		throw CException("Impossible d'allouer une matrice avec des 0 lignes ou colonnes.");
	}
}

template<class Type> unsigned int CMatrice<Type>::MATObtenirColonnes()
{
	return uiMATcolonnes;
}

template<class Type> unsigned int CMatrice<Type>::MATObtenirLignes()
{
	return uiMATlignes;
}

template<class Type> CMatrice<Type> & CMatrice<Type>::operator/(double dParam)
{
	if (dParam != 0) {
		CMatrice<Type> *temp = new CMatrice<Type>(*this);
		for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
			for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
				temp->MATObtenirDonnees()[uiLigne][uiColonne] /= dParam;
			}
		}
		return *temp;
	}
	else {
		throw CException("Division par 0 !");
	}
}

template<class Type> CMatrice<Type>& CMatrice<Type>::operator=(CMatrice & MATParam)
{
	MATSetDimensions(MATParam.uiMATcolonnes,MATParam.uiMATlignes);
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			ptMATmatrice[uiLigne][uiColonne] = MATParam.ptMATmatrice[uiLigne][uiColonne];
		}
	}
	return *this;

}

template<class Type> CMatrice<Type>& CMatrice<Type>::operator-(CMatrice & MATParam)
{
	if (uiMATcolonnes == MATParam.MATObtenirColonnes() && uiMATlignes == MATParam.MATObtenirLignes()) {
		CMatrice<Type> *temp = new CMatrice<Type>(*this);
		for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
			for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
				temp->MATObtenirDonnees()[uiLigne][uiColonne] -= MATParam.ptMATmatrice[uiLigne][uiColonne];
			}
		}
		return *temp;
	}
	else {
		throw CException("Soustraction de 2 matrices qui n'ont pas la meme taille.");
	}
}

template<class Type> Type ** CMatrice<Type>::MATObtenirDonnees()
{
	return ptMATmatrice;
}

template<class Type> void CMatrice<Type>::MATAfficherMatrice()
{
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			cout << ptMATmatrice[uiLigne][uiColonne] << "\t";
		}
		cout << endl;
	}
}

template<class Type> CMatrice<Type>::~CMatrice()
{
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		delete[] ptMATmatrice[uiLigne];
	}
	delete[] ptMATmatrice;
}
template<class Type> CMatrice<Type> & CMatrice<Type>::operator*(double dParam)
{
	CMatrice<Type> *temp = new CMatrice<Type>(*this);
	for (unsigned int uiCompteLignes = 0; uiCompteLignes < uiMATlignes; uiCompteLignes++) {
		for (unsigned int uiCompteCol = 0; uiCompteCol < uiMATcolonnes; uiCompteCol++) {

			temp->MATObtenirDonnees()[uiCompteLignes][uiCompteCol] *= dParam;
		}
	}
	return *temp;
}


template<class Type> CMatrice<Type> & CMatrice<Type>::operator*(CMatrice<Type> & MATTemp)
{
	// TODO: insérer une instruction return ici
	if (MATObtenirColonnes() == MATTemp.MATObtenirLignes()) {
		CMatrice<Type> *temp = new CMatrice<Type>();
		temp->MATSetDimensions(MATObtenirLignes(), MATTemp.MATObtenirColonnes());
		//on parcourt les lignes de la nouvelle matrice
		for (unsigned int uiCompteNouvMatLigne = 0; uiCompteNouvMatLigne < temp->MATObtenirLignes(); uiCompteNouvMatLigne++) {
			//on parcourt les colonnes de chaque ligne de la nouvelle matrice
			for (unsigned int uiCompteNouvMatCol = 0; uiCompteNouvMatCol < temp->MATObtenirColonnes(); uiCompteNouvMatCol++) {
				//on rempli la nouvelle matrice. On a un seul compteur car pour faire le produit
				//de 2 matrices il faut NbLigneA = NbColB
				for (unsigned int uiCompteur = 0; uiCompteur < MATTemp.MATObtenirLignes(); uiCompteur++) {

					temp->ptMATmatrice[uiCompteNouvMatLigne][uiCompteNouvMatCol] +=
						ptMATmatrice[uiCompteNouvMatLigne][uiCompteur] * MATTemp.ptMATmatrice[uiCompteur][uiCompteNouvMatCol];


				}//on parcourt la matrice à remplir et on met la somme des produit dans chaque case
			}
		}
		return *temp;
	}

}



template<class Type> CMatrice<Type> & CMatrice<Type>::operator+(CMatrice<Type> & MATTemp)
{
	if ((MATObtenirLignes() == MATTemp.MATObtenirLignes()) && (MATObtenirColonnes() == MATTemp.MATObtenirColonnes())) {
		CMatrice<Type> *temp = new CMatrice<Type>(*this);
		for (unsigned int uiCompteLignes = 0; uiCompteLignes < uiMATlignes; uiCompteLignes++) {
			for (unsigned int uiCompteCol = 0; uiCompteCol < uiMATcolonnes; uiCompteCol++) {

				temp->MATObtenirDonnees()[uiCompteLignes][uiCompteCol] += MATTemp.ptMATmatrice[uiCompteLignes][uiCompteCol];
			}
		}
		return *temp;
	}
	else {
		throw CException("pas les bonnes dimensions");
	}

}

#endif // CMATRICE_H