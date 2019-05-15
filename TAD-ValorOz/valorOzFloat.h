#ifndef VALOROZ_H
#define VALOROZ_H

//Importar las librerias necesarias
#include "valorOz.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ValorOzFloat : public ValorOz{
    private:
        double val;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzFloat(double _val);
        double getVal();
};

#endif
