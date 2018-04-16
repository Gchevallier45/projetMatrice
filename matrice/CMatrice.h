#ifndef CMATRICE_H
#define CMATRICE_H

#include <iostream>
#include <vector>
#include "CException.h"

using namespace std;

template <class Type> class CMatrice
{
	vector<vector<Type>> vMATmatrice;
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
	void MATAfficherMatrice();
	void MATInitMatrice();
	void MATSetDimensions(unsigned int uiLignes, unsigned int uiColonnes);
	void MATSetElement(unsigned int uiLigne, unsigned int uiColonne, Type element);
	Type MATGetElement(unsigned int uiLigne, unsigned int uiColonne);
	unsigned int MATObtenirColonnes();
	unsigned int MATObtenirLignes();
	CMatrice<Type>& MATTransposee();
	~CMatrice();
};

template<class Type> CMatrice<Type>::CMatrice()
{
	uiMATlignes = 0;
	uiMATcolonnes = 0;
}

template<class Type> CMatrice<Type>::CMatrice(CMatrice & MATParam)
{
	MATSetDimensions(MATParam.MATObtenirLignes(), MATParam.MATObtenirColonnes());
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			MATSetElement(uiLigne, uiColonne, MATParam.MATGetElement(uiLigne, uiColonne));
		}
	}
}

template<class Type> void CMatrice<Type>::MATInitMatrice() {
	cin >> uiMATlignes;
	cin >> uiMATcolonnes;
	MATSetDimensions(uiMATlignes, uiMATcolonnes);
	//vMATmatrice = new Type*[uiMATlignes];
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			cin >> vMATmatrice.at(uiLigne).at(uiColonne);
		}
	}
}

template<class Type> void CMatrice<Type>::MATSetDimensions(unsigned int uiLignes, unsigned int uiColonnes)
{
	if (uiLignes != 0 && uiColonnes != 0) {
		uiMATcolonnes = uiColonnes;
		uiMATlignes = uiLignes;
		vMATmatrice.clear();
		vMATmatrice = vector<vector<Type>>(uiMATlignes, vector<Type>(uiMATcolonnes));
	}
	else {
		throw CException("Impossible d'allouer une matrice 0x0");
	}
}

template<class Type> void CMatrice<Type>::MATSetElement(unsigned int uiLigne, unsigned int uiColonne, Type element)
{
	vMATmatrice[uiLigne][uiColonne] = element;
}

template<class Type> Type CMatrice<Type>::MATGetElement(unsigned int uiLigne, unsigned int uiColonne)
{
	return vMATmatrice[uiLigne][uiColonne];
}

template<class Type> unsigned int CMatrice<Type>::MATObtenirColonnes()
{
	return uiMATcolonnes;
}

template<class Type> unsigned int CMatrice<Type>::MATObtenirLignes()
{
	return uiMATlignes;
}

template<class Type> CMatrice<Type>& CMatrice<Type>::MATTransposee()
{
	CMatrice<Type> *temp = new CMatrice<Type>();
	temp->MATSetDimensions(MATObtenirColonnes(), MATObtenirLignes());
	for (unsigned int uiLigne = 0; uiLigne < temp->MATObtenirLignes(); uiLigne++) {
		for (unsigned int uiColonne = 0; uiColonne <  temp->MATObtenirColonnes(); uiColonne++) {
			temp->MATSetElement(uiLigne, uiColonne, MATGetElement(uiColonne,uiLigne));
		}
	}
	return *temp;
}

template<class Type> CMatrice<Type> & CMatrice<Type>::operator/(double dParam)
{
	if (dParam != 0) {
		CMatrice<Type> *temp = new CMatrice<Type>(*this);
		for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
			for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
				temp->MATSetElement(uiLigne, uiColonne, temp->MATGetElement(uiLigne, uiColonne) / dParam);
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
	MATSetDimensions(MATParam.MATObtenirLignes(), MATParam.MATObtenirColonnes());
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			MATSetElement(uiLigne, uiColonne, MATParam.MATGetElement(uiLigne, uiColonne));
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
				temp->MATSetElement(uiLigne, uiColonne, temp->MATGetElement(uiLigne, uiColonne) - MATParam.MATGetElement(uiLigne, uiColonne));
			}
		}
		return *temp;
	}
	else {
		throw CException("Soustraction de 2 matrices qui n'ont pas la meme taille.");
	}
}


template<class Type> void CMatrice<Type>::MATAfficherMatrice()
{
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			cout << vMATmatrice[uiLigne][uiColonne] << "\t";
		}
		cout << endl;
	}
}

template<class Type> CMatrice<Type>::~CMatrice()
{
}

template<class Type> CMatrice<Type> & CMatrice<Type>::operator*(double dParam)
{
	CMatrice<Type> *temp = new CMatrice<Type>(*this);
	for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
		for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
			temp->MATSetElement(uiLigne, uiColonne, temp->MATGetElement(uiLigne, uiColonne) * dParam);
		}
	}
	return *temp;
}


template<class Type> CMatrice<Type> & CMatrice<Type>::operator*(CMatrice<Type> & MATParam)
{
	if (MATObtenirColonnes() == MATParam.MATObtenirLignes()) {
		CMatrice<Type> *temp = new CMatrice<Type>();
		temp->MATSetDimensions(MATObtenirLignes(), MATParam.MATObtenirColonnes());
		//on parcourt les lignes de la nouvelle matrice
		for (unsigned int uiLigne = 0; uiLigne < temp->MATObtenirLignes(); uiLigne++) {
			//on parcourt les colonnes de chaque ligne de la nouvelle matrice
			for (unsigned int uiColonne = 0; uiColonne < temp->MATObtenirColonnes(); uiColonne++) {
				//on rempli la nouvelle matrice. On a un seul compteur car pour faire le produit
				//de 2 matrices il faut NbLigneA = NbColB
				for (unsigned int uiCompteur = 0; uiCompteur < MATParam.MATObtenirLignes(); uiCompteur++) {

					//temp->ptMATmatrice[uiCompteNouvMatLigne][uiCompteNouvMatCol] +=
						//ptMATmatrice[uiCompteNouvMatLigne][uiCompteur] * MATTemp.ptMATmatrice[uiCompteur][uiCompteNouvMatCol];
					temp->MATSetElement(uiLigne, uiColonne, temp->MATGetElement(uiLigne, uiColonne) +
						MATGetElement(uiLigne, uiCompteur) * MATParam.MATGetElement(uiCompteur, uiColonne));


				}//on parcourt la matrice à remplir et on met la somme des produit dans chaque case
			}
		}
		return *temp;
	}

}

template<class Type> CMatrice<Type> & CMatrice<Type>::operator+(CMatrice<Type> & MATTemp)
{
	if (uiMATcolonnes == MATParam.MATObtenirColonnes() && uiMATlignes == MATParam.MATObtenirLignes()) {
		CMatrice<Type> *temp = new CMatrice<Type>(*this);
		for (unsigned int uiLigne = 0; uiLigne < uiMATlignes; uiLigne++) {
			for (unsigned int uiColonne = 0; uiColonne < uiMATcolonnes; uiColonne++) {
				temp->MATSetElement(uiLigne, uiColonne, temp->MATGetElement(uiLigne, uiColonne) + MATParam.MATGetElement(uiLigne, uiColonne));
			}
		}
		return *temp;
	}
	else {
		throw CException("Addition de 2 matrices qui n'ont pas la meme taille.");
	}
}

template<class Type> CMatrice<Type> & operator*(double dParam, CMatrice<Type> & MATTemp)
{
	CMatrice<Type> *temp = new CMatrice<Type>(MATTemp * dParam);
	return *temp;
}

#endif // CMATRICE_H