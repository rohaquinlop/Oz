#include "valorOz.h"
#include <iostream>
#include <string>

#ifndef VALOROZUNLINKED_H
#define VALOROZUNLINKED_H

using namespace std;

class ValorOzUnlinked : public ValorOz{
    private:
        //Atributo de la clase
        string val;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzUnlinked(string _type, string _val);
        string getVal();
};

#endif
