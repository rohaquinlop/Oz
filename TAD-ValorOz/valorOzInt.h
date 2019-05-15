#ifndef VALOROZ_H
#define VALOROZ_H

//Importar las librerias necesarias
#include "valorOz.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ValorOzInt : public ValorOz{
    private:
        int val;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzInt(int _val);
        string getVal();
};

#endif
