#ifndef VALOROZ_H
#define VALOROZ_H

//Importar las librerias necesarias
#include "valorOz.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ValorOzVar : public ValorOz{
    private:
        string var;
    public:
        //Constructor de la clase, metodos set y get
        ValorOzVar(string _var);
        string getVal();
};

#endif
