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

ValorOz* Almacen :: buildValorOz(string _type, string _val){
	ValorOz* v;
	std::string::size_type sz;
	if( _type == "unLinked" ){
		v = new ValorOzUnlinked(_type, _val);
	}else if( _type == "int" ){
		v = new ValorOzInt(_type, stoi(_val) );
	}else if( _type == "float" ){
		v = new ValorOzFloat(_type, stod(_val, &sz) );
	}else if( _type == "var" ){
		v = new ValorOzVar(_type, _val);
	}else if( _type == "rec" ){
		//Falta implementar...
		//v = new ValorOzRec(_type, _val);
	}

	return v;
}

void  Almacen :: addVal( map<string, string> _m ){
	/*
	Esta funcion agrega una variable al almacen junto con su respectivo ValorOz
	*/
	string c1 = _m["c1"];
	string c2 = _m["c2"];
	Operacion o;
	ValorOz* v;

	if( o.evalType(c1) == "var" && o.evalType(c2) != "var" ){
		/*
		Si ambas campos ingresados son de tipos diferentes, y el primer
		campo es una variable y el segundo no es una variable, entonces
		se verifica si la variable existe en el almacen, en caso de que no
		entonces asigna la variable con el Valor Oz que se ingreso
		*/

		map<string, ValorOz*>::iterator it;
		it = almacen.find(c1);

		if( it == almacen.end() ){
			v = buildValorOz( o.evalType(c2), c2 );
			almacen[c1] = v;
		}else{
			ValorOz* cmp = almacen[c1];
		}
	}

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