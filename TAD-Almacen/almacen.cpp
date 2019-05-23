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

extern bool fail;
extern bool twoLevelLink;

Almacen :: Almacen(){
}

void  Almacen :: addVal( map<string, string> _m ){
	/*
	Esta funcion recibe como parametro el mapa que retorna la funcion parse
	y añade la variable al almacen con su respectivo Valor Oz
	*/
	string c1 = _m["c1"];
	string c2 = _m["c2"];
	Operacion o;
	ValorOz* v;

	if( o.evalType(c1) == "var" && o.evalType(c2) != "var" ){
		/*
		Si ambos campos ingresados son de tipos diferentes, y el primer
		campo es una variable y el segundo no es una variable, entonces
		se verifica si la variable existe en el almacen, en caso de que no
		entonces asigna la variable con el Valor Oz que se ingreso, en caso
		de que si exista entonces se verifica si el valorOz que se desea ingresar
		sea el mismo.
		*/

		if( !existVar(c1) || !isLinked(c1) ){
			v = o.buildValorOz( o.evalType(c2), c2 );
			almacen[c1] = v;
		}else{
			ValorOz* cmp = almacen[c1];
			v = o.buildValorOz( o.evalType(c2), c2 );
			if( infoVal(v) != infoVal(cmp) ){
				fail = true;
			}
		}

	}else if( o.evalType(c2) == "var" && o.evalType(c1) != "var" ){
		if( !existVar(c2) || !isLinked(c2) ){
			v = o.buildValorOz( o.evalType(c1), c1 );
			almacen[c2] = v;
		}else{
			ValorOz* cmp = almacen[c2];
			v = o.buildValorOz( o.evalType(c1), c1 );
			if( infoVal(v) != infoVal(cmp) ){
				fail = true;
			}
		}
	}else if( o.evalType(c1) == "var" && o.evalType(c2) == "var" ){
		//En caso de que ambos campos sean variables, entonces se procede a preguntar si existe
		//o no existe cada campo
		string father;

		if( !existVar(c1) && existVar(c2) ){
			v = o.buildValorOz( o.evalType(c2), c2 );
			father = findFather(v);
			v = o.buildValorOz( o.evalType(c2), father );
			almacen[c1] = v;
			twoLevelLink = true;
		}else if( existVar(c1) && !existVar(c2) ){
			v = o.buildValorOz( o.evalType(c1), c1 );
			father = findFather(v);
			v = o.buildValorOz( o.evalType(c1), father );
			almacen[c2] = v;
			twoLevelLink = true;
		}else if( existVar(c1) && existVar(c2) ){
			//En caso de que ambos existan y sean variables entonces se debe saber
			//Los valores de dichas variables
			if( !isLinked(c1) ){
				v = o.buildValorOz( o.evalType(c2), c2 );
				almacen[c1] = v;
			}else if( !isLinked(c2) ){
				v = o.buildValorOz( o.evalType(c1), c1 );
				almacen[c2] = v;
			}else if( infoVar( infoVar(c1) ) != infoVar( infoVar(c2) ) ){
				fail = true;
			}
		}
	}

}

void Almacen :: showInfo(){
	/*
	Esta funcion muestra el almacen
	*/
	map<string, ValorOz*>::iterator it;
	string type;

	cout << "- - - Estado del Almacen - - -\n";

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
	/*
	Esta funcion recibe como parametro un puntero de ValorOz y
	retorna la representacion como string del ValorOz
	*/

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
	/*
	Esta funcion recibe como parametro una variable y consulta el Valor Oz que
	tiene asociado en el almacen y retorna su representacion como string,
	para esto usa la funcion infoVal
	*/
	ValorOz* aux = almacen[name];

	return infoVal(aux);
}

bool Almacen :: isLinked(string name){
	/*
	Esta funcion recibe como parametro un string que representa la variable
	que va a consultar en el almacen y llama la funcion infoVar con parametro
	el string que recibio y así verifica si el valor que retorna la funcion infoVar
	pertence a la representacion de los ValorOz sin ligar
	*/
	if( infoVar(name) == "_" ){
		return false;
	}
	return true;
}

string Almacen :: findFather(ValorOz* son){
	/*
	Esta funcion recibe como parametro un puntero a ValorOz, y lo que hace es encontrar el
	padre de un Valor Oz para asi mantener la ligadura a dos niveles, esta funcion se usa
	cuando se desea agregar un Valor Oz que va a estar ligado a una variable
	*/
	string type = son->getType(), father = infoVal(son);

	while( type == "var" ){
		father = infoVal(son);
		son = almacen[ infoVal(son) ];
		type = son->getType();
	}

	return father;

}

bool Almacen :: existVar(string name){
	/*
	Esta funcion recibe como parametro un string que representa una variable, la cual
	se busca en el almacen y retorna true si existe o false en caso contrario
	*/

	map<string, ValorOz*>::iterator it;
	it = almacen.find(name);

	if( it != almacen.end() ){
		return true;
	}else{
		return false;
	}

}

void Almacen :: keepTwoLevel(){
	map<string, ValorOz*>::iterator it;
	string father;

	for(it = almacen.begin(); it != almacen.end(); it++){
		ValorOz* v = it->second;
		if( v->getType() == "var" ){
			father = findFather(v);
			if( father != infoVal(v) ){
				((ValorOzVar*)v)->setVar(father);
			}
		}
	}
}