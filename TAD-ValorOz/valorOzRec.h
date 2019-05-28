#include "valorOz.h"
#include <iostream>
#include <string>
#include <map>

#ifndef VALOROZREC_H
#define VALOROZREC_H

using namespace std;

class ValorOzRec : public ValorOz{
    private:
        string name;
        map<string, ValorOz*> m;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzRec(string _type, string _name, map<string, ValorOz*> _m);
        string getVal();
        string getCamps();
        map<string, ValorOz*> getMap();
};

#endif
