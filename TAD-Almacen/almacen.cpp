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
		cout << it->first << " -> ";
		if( (it->second)->getType() == "unLinked" ){
			cout << ((ValorOzUnlinked*)(it->second))->getVal() << "\n";
		}else if( (it->second)->getType() == "int" ){
			cout << ((ValorOzInt*)(it->second))->getVal() << "\n";
		}else if( (it->second)->getType() == "float" ){
			cout << ((ValorOzFloat*)(it->second))->getVal() << "\n";
		}else if( (it->second)->getType() == "var" ){
			cout << ((ValorOzVar*)(it->second))->getVal() << "\n";
		}
		/*
		//Los registros aun no están implementados
		else if( (it->second)->getType() == "rec" ){
			cout << ((ValorOzRec*)(it->second))->getVal() << "\n";
		}
		*/
	}
}

void  Almacen :: addVal(string name, ValorOz* valOz){
	almacen[name] = valOz;
}