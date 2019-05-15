#ifndef VALOROZ_H
#define VALOROZ_H

//Importar las librerias necesarias
#include "valorOz.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ValorOzUnlinked : public ValorOz{
    private:
        //Atributo de la clase
        string val;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzUnlinked(string _val);
        void setVal(string _var);
        string getVal();
};

#endif
