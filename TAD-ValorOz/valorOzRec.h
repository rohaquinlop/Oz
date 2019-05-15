#ifndef VALOROZ_H
#define VALOROZ_H

//Importar las librerias necesarias
#include "valorOz.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ValorOzRec : public ValorOz{
    private:
        string name;
        map<string, ValorOz> m;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzRec(string _name, map<string, ValorOz> _m);
        string getVal();
};

#endif
