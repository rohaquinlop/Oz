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
	string type;

	for(it = almacen.begin(); it != almacen.end(); it++){
		cout << it->first << " -> ";
		type = (it->second)->getType();

		if( type == "unLinked" ){
			cout << infoVal( (it->second) ) << "\n";
		}else if( type == "int" ){
			cout << infoVal( (it->second) ) << "\n";
		}else if( type == "float" ){
			cout << infoVal( (it->second) ) << "\n";
		}else if( type == "var" ){
			cout << infoVal( (it->second) ) << "\n";
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
	/*
	Esta funcion agrega una valorOz al almacen junto con su respectiva variable
	Falta implementar...
	*/
	almacen[name] = valOz;
}

string Almacen :: infoVal( ValorOz* valOz ){

	if( valOz->getType() == "unLinked" ){
		return ((ValorOzUnlinked*)valOz)->getVal();
	}else if( valOz->getType() == "int" ){
		return ((ValorOzInt*)valOz)->getVal();
	}else if( valOz->getType() == "float" ){
		return ((ValorOzFloat*)valOz)->getVal();
	}else if( valOz->getType() == "var" ){
		return ((ValorOzVar*)valOz)->getVal();
	}

}

string Almacen :: infoVar( string name ){
	ValorOz* aux = almacen[name];

	return infoVal(aux);
}

bool Almacen :: isLinked(string name){
	ValorOz* aux = almacen[name];
	if( (aux->getType()) == "unLinked" ){
		return false;
	}
	return true;
}

string Almacen :: findFather(ValorOz* son){
	/*
	El objetivo de esta funcion es encontrar la variable padre para un valor cuando
	se haga la ligadura con una variable para asi mantener el arbol a 2 niveles.
	*/
	string type = son->getType(), father = infoVal(son);

	while( type == "var" ){
		father = infoVal(son);
		son = almacen[ infoVal(son) ];
		type = son->getType();
	}

	return father;

}