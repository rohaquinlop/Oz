#include "almacen.h"
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

using namespace std;

Almacen :: Almacen(){
}

void Almacen :: showInfo(){
	map<string, ValorOz*>::iterator it;

	for(it = almacen.begin(); it != almacen.end(); it++){
		cout << it->first << " -> " << ((ValorOzInt*)(it->second))->getVal();
	}
}

void  Almacen :: addVal(string name, ValorOz* valOz){
	almacen[name] = valOz;
}