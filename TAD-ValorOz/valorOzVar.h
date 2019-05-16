#include "valorOz.h"
#include <iostream>
#include <string>

#ifndef VALOROZVAR_H
#define VALOROZVAR_H

using namespace std;

class ValorOzVar : public ValorOz{
    private:
        string var;
    public:
        //Constructor de la clase, metodos set y get
        ValorOzVar(string _type, string _var);
        string getVal();
};

#endif
