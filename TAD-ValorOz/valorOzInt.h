#include "valorOz.h"
#include <iostream>
#include <string>

#ifndef VALOROZINT_H
#define VALOROZINT_H

using namespace std;

class ValorOzInt : public ValorOz{
    private:
        int val;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzInt(string _type, int _val);
        string getVal();
};

#endif
