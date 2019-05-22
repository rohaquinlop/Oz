#include "../TAD-ValorOz/valorOz.h"
#include "../TAD-ValorOz/valorOzFloat.h"
#include "../TAD-ValorOz/valorOzInt.h"
#include "../TAD-ValorOz/valorOzRec.h"
#include "../TAD-ValorOz/valorOzUnlinked.h"
#include "../TAD-ValorOz/valorOzVar.h"
#include "../Operacion/operacion.h"
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

#ifndef ALMACEN_H
#define ALMACEN_H

using namespace std;

class Almacen{
    private:
        map<string, ValorOz*> almacen;
    public:
        Almacen();
		ValorOz* buildValorOz(string _type, string _val);
        void showInfo();
        void addVal( map<string, string> _m );
        string infoVal(ValorOz* valOz);
        string infoVar(string name);
        bool isLinked(string name);
        string findFather(ValorOz* son);
};

#endif
