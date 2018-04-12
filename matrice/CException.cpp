#include "stdafx.h"
#include "CException.h"

using namespace std;

CException::CException(string sErreur){
    sEXCErreur = sErreur;
}

CException::CException(){
    sEXCErreur = "";
}

void CException::EXCAfficherMessage(){
	if(sEXCErreur.length() != 0) {
		cout << "Exception : " << sEXCErreur << endl;
	}
	else {
		cout << "Exception inconnue." << endl;
	}

}
