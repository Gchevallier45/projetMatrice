#ifndef CEXCEPTION_H
#define CEXCEPTION_H

#include <string>
#include <iostream>

using namespace std;

class CException
{
    private:
        string sEXCErreur;
    public:
        CException();
        CException(string sErreur);
        void EXCAfficherMessage();
};

#endif // CEXCEPTION_H