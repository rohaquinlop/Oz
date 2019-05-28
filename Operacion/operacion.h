#ifndef OPERACION_H
#define OPERACION_H

#include "../TAD-ValorOz/valorOz.h"
#include "../TAD-ValorOz/valorOzFloat.h"
#include "../TAD-ValorOz/valorOzInt.h"
#include "../TAD-ValorOz/valorOzRec.h"
#include "../TAD-ValorOz/valorOzUnlinked.h"
#include "../TAD-ValorOz/valorOzVar.h"
#include <iostream>
#include <map>

using namespace std;

class Operacion{
    public:
        //Metodos
        map<string, string> parse( string s );
        map<string, string> parseRec(string s);
        bool isInt( string s );
        string evalType( string s );
        ValorOz* buildValorOz( string _type, string _val );
        ValorOz* buildValRec( string _type,string _val );
        bool compareRec( ValorOz* v, ValorOz* cmp );
};

#endif
