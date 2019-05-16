#include "valorOz.h"
#include <iostream>
#include <string>

#ifndef VALOROZFLOAT_H
#define VALOROZFLOAT_H

using namespace std;

class ValorOzFloat : public ValorOz{
    private:
        double val;
    public:
        //Constructor de la clase
        ValorOzFloat(string _type, double _val);
        //Metodo get
        string getVal();
};

#endif
