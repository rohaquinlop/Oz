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
#include <list>
#include <algorithm>

using namespace std;

Almacen :: Almacen(){
	this->fail = false;
	this->twoLevelLink = false;
}

Almacen :: Almacen( map<string, ValorOz*> _almacen ){
	this->fail = false;
	this->twoLevelLink = false;
	this->almacen = _almacen;
}

map<string, ValorOz*> Almacen :: getAlmacen(){
	return this->almacen;
}

bool Almacen :: getFail(){
	return this->fail;
}

bool Almacen :: getTwoLevelLink(){
	return this->twoLevelLink;
}
void Almacen :: swapFail(){
	this->fail = !this->fail;
}

void Almacen :: swapTwoLevelLink(){
	this->twoLevelLink = !this->twoLevelLink;
}

void Almacen :: addVal( string c1, string c2 ){
	/*
	Esta funcion recibe como parametro el mapa que retorna la funcion parse
	y añade la variable al almacen con su respectivo Valor Oz
	*/

	Operacion o;
	ValorOz* v;

	if( (o.evalType(c1) == "var" || o.evalType(c1) == "camp") && o.evalType(c2) != "var" ){
		/*
		Si ambos campos ingresados son de tipos diferentes, y el primer
		campo es una variable y el segundo no es una variable, entonces
		se verifica si la variable existe en el almacen, en caso de que no
		entonces asigna la variable con el Valor Oz que se ingreso, en caso
		de que si exista entonces se verifica si el valorOz que se desea ingresar
		sea el mismo.
		*/

		if( !existVar(c1) ){
			if( o.evalType(c2) != "rec" )
				v = o.buildValorOz( o.evalType(c2), c2 );
			else{
				v = o.buildValRec( o.evalType(c2), c2 );
			}
			almacen[c1] = v;
		}
		else if( existVar(c1) && c2 != "_" ){
			//En caso de que ambos existan y sean variables entonces se debe saber
			//Los valores de dichas variables
			if( !isLinked(c1) ){
				if( o.evalType(c2) != "rec" )
					v = o.buildValorOz( o.evalType(c2), c2 );
				else
					v = o.buildValRec( o.evalType(c2), c2 );
				almacen[c1] = v;
			}else{
				if( o.evalType( infoVar(c1) ) == "var" ){
					if( o.evalType( infoVar( infoVar(c1) ) ) == "unLinked" ){
						if( o.evalType(c2) != "rec" )
							v = o.buildValorOz( o.evalType(c2), c2 );
						else
							v = o.buildValRec( o.evalType(c2), c2 );
						almacen[ infoVar(c1) ] = v;
						swapTwoLevelLink();
					}else{
						ValorOz* cmp = almacen[  infoVar(c1) ];
						if( o.evalType(c2) != "rec" )
							v = o.buildValorOz( o.evalType(c2), c2 );
						else
							v = o.buildValRec( o.evalType(c2), c2 );
						if( infoVal(v) != infoVal(cmp) ){
							swapFail();
						}
					}
				}else{
					ValorOz* cmp = almacen[ c1 ];
					if( o.evalType(c2) != "rec" )
						v = o.buildValorOz( o.evalType(c2), c2 );
					else
						v = o.buildValRec( o.evalType(c2), c2 );
					if( infoVal(v) != infoVal(cmp) ){
						swapFail();
					}
				}
			}
		}

	}
	else if( o.evalType(c2) == "var" && (o.evalType(c1) != "var" && o.evalType(c1) != "camp") ){
		if( !existVar(c2) ){
			if( o.evalType(c1) != "rec" )
				v = o.buildValorOz( o.evalType(c1), c1 );
			else
				v = o.buildValRec( o.evalType(c1), c1 );
			almacen[c2] = v;
		}
		else if( existVar(c2) && c1 != "_" ){
			//En caso de que ambos existan y sean variables entonces se debe saber
			//Los valores de dichas variables
			if( !isLinked(c2) ){
				if( o.evalType(c1) != "rec" )
					v = o.buildValorOz( o.evalType(c1), c1 );
				else
					v = o.buildValRec( o.evalType(c1), c1 );
				almacen[c2] = v;
			}else{
				if( o.evalType( infoVar(c2) ) == "var" ){
					if( o.evalType( infoVar( infoVar(c2) ) ) == "unLinked" ){
						if( o.evalType(c1) != "rec" )
							v = o.buildValorOz( o.evalType(c1), c1 );
						else
							v = o.buildValRec( o.evalType(c1), c1 );
						almacen[ infoVar(c2) ] = v;
						swapTwoLevelLink();
					}else{
						ValorOz* cmp = almacen[ infoVar(c2) ];
						if( o.evalType(c1) != "rec" )
							v = o.buildValorOz( o.evalType(c1), c1 );
						else
							v = o.buildValRec( o.evalType(c1), c1 );
						if( infoVal(v) != infoVal(cmp) ){
							swapFail();
						}
					}
				}else{
					ValorOz* cmp = almacen[ c2 ];
					if( o.evalType(c1) != "rec" )
						v = o.buildValorOz( o.evalType(c1), c1 );
					else
						v = o.buildValRec( o.evalType(c1), c1 );
					if( infoVal(v) != infoVal(cmp) ){
						swapFail();
					}
				}
			}
		}
	}
	else if( (o.evalType(c1) == "var" || o.evalType(c1) == "camp") && o.evalType(c2) == "var" ){
		//En caso de que ambos campos sean variables, entonces se procede a preguntar si existe
		//o no existe cada campo
		string father;

		if( !existVar(c1) && o.evalType(c1) == "camp" ){
			v = o.buildValorOz( o.evalType(c2), c2 );
			almacen[c1] = v;
		}
		else if( !existVar(c1) && existVar(c2) ){
			v = o.buildValorOz( o.evalType(c2), c2 );
			father = findFather(v);
			v = o.buildValorOz( o.evalType(c2), father );
			almacen[c1] = v;
			swapTwoLevelLink();
		}
		else if( existVar(c1) && !existVar(c2) ){
			v = o.buildValorOz( o.evalType(c1), c1 );
			father = findFather(v);
			v = o.buildValorOz( o.evalType(c1), father );
			almacen[c2] = v;
			swapTwoLevelLink();
		}
		else if( existVar(c1) && existVar(c2) ){
			//En caso de que ambos existan y sean variables entonces se debe saber
			//Los valores de dichas variables
			if( !isLinked(c1) ){
				v = o.buildValorOz( o.evalType(c2), c2 );
				almacen[c1] = v;
				swapTwoLevelLink();
			}
			else if( !isLinked(c2) ){
				v = o.buildValorOz( o.evalType(c1), c1 );
				almacen[c2] = v;
				swapTwoLevelLink();
			}else{
				if( o.evalType( infoVar(c1) ) == "var" && o.evalType( infoVar(c2) ) != "var" ){
					if( o.evalType( infoVar( infoVar(c1) ) ) == "unLinked" ){
						v = o.buildValorOz( o.evalType(c2), c2 );
						almacen[ infoVar(c1) ] = v;
						swapTwoLevelLink();
					}else{
						ValorOz* cmp = almacen[ infoVar( infoVar(c1) ) ];
						v = o.buildValorOz( o.evalType(c2), c2 );
						if( infoVal(v) != infoVal(cmp) ){
							swapFail();
						}
					}
				}
				else if( o.evalType( infoVar(c2) ) == "var" && o.evalType( infoVar(c1) ) != "var" ){
					if( o.evalType( infoVar( infoVar(c2) ) ) == "unLinked" ){
						v = o.buildValorOz( o.evalType(c1), c1 );
						almacen[ infoVar(c2) ] = v;
						swapTwoLevelLink();
					}else{
						ValorOz* cmp = almacen[ infoVar( infoVar(c2) ) ];
						v = o.buildValorOz( o.evalType(c1), c1 );
						if( infoVal(v) != infoVal(cmp) ){
							swapFail();
						}
					}
				}
				else if( o.evalType( infoVar(c1) ) == "var" && o.evalType( infoVar(c2) ) == "var" ){
					if( o.evalType( infoVar( infoVar(c1) ) ) == "unLinked" ){
						v = o.buildValorOz( o.evalType(c2), c2 );
						almacen[ infoVar(c1) ] = v;
						swapTwoLevelLink();
					}
					else if( o.evalType( infoVar( infoVar(c2) ) ) == "unLinked" ){
						v = o.buildValorOz( o.evalType(c1), c1 );
						almacen[ infoVar(c2) ] = v;
						swapTwoLevelLink();
					}
					else if( infoVar( infoVar(c1) ) != infoVar( infoVar(c2) ) ){
						swapFail();
					}
				}else{
					if( o.evalType( infoVar(c1) ) == "rec" && o.evalType( infoVar(c1) ) != "rec" ){
						swapFail();
					}
					else if( o.evalType( infoVar(c1) ) != "rec" && o.evalType( infoVar(c1) ) == "rec" ){
						swapFail();
					}
					else if( o.evalType( infoVar(c1) ) == "rec" && o.evalType( infoVar(c1) ) == "rec" ){
						v = almacen[ c1 ];
						ValorOz* cmp = almacen[ c2 ];
						if( !o.compareRec(v, cmp) )
							swapFail();
						else
							if ( !linkRec(v, cmp) ){
								swapFail();
								cout << "La ligadura de los registros no es posible " << infoVal(v) << " " << infoVal(cmp) <<"\n";
							}
					}
				}
			}
		}
	}else if( o.evalType(c1) != "var" && o.evalType(c2) != "var" ){
		if( c2 != "_" && c1 != "_" ){
			ValorOz* cmp;

			if( o.evalType(c1) != "rec" )
				v = o.buildValorOz( o.evalType(c1), c1 );
			else
				v = o.buildValRec( o.evalType(c1), c1 );

			if( o.evalType(c2) != "rec" )
				cmp = o.buildValorOz( o.evalType(c2), c2 );
			else
				cmp = o.buildValRec( o.evalType(c2), c2 );

				if( o.evalType(c1) == "rec" && o.evalType(c2) == "rec" ){
					if( !o.compareRec(v, cmp) )
						swapFail();
					else
						if ( !linkRec(v, cmp) ){
							swapFail();
							cout << "La ligadura de los registros no es posible " << infoVal(v) << " " << infoVal(cmp) <<"\n";
						}
				}else
					if( infoVal(v) != infoVal(cmp) )
						swapFail();
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
			cout << it->first << " -> " << infoVal( (it->second) ) << "\n";
	}
}

string Almacen :: infoVal( ValorOz* valOz ){
	/*
	Esta funcion recibe como parametro un puntero de ValorOz y
	retorna la representacion como string del ValorOz
	*/

	if( valOz->getType() == "unLinked" ){
		return ((ValorOzUnlinked*)valOz)->getVal();
	}
	else if( valOz->getType() == "int" ){
		return ((ValorOzInt*)valOz)->getVal();
	}
	else if( valOz->getType() == "float" ){
		return ((ValorOzFloat*)valOz)->getVal();
	}
	else if( valOz->getType() == "var" ){
		return ((ValorOzVar*)valOz)->getVal();
	}
	else if( valOz->getType() == "rec" ){
		return ((ValorOzRec*)valOz)->getVal();
	}

}

string Almacen :: infoVar( string name ){
	/*
	Esta funcion recibe como parametro una variable y consulta el Valor Oz que
	tiene asociado en el almacen y retorna su representacion como string,
	para esto usa la funcion infoVal
	*/

	return infoVal( almacen[name] );
}

bool Almacen :: isLinked(string name){
	/*
	Esta funcion recibe como parametro un string que representa la variable
	que va a consultar en el almacen y llama la funcion infoVar con parametro
	el string que recibio y así verifica si el valor que retorna la funcion infoVar
	pertence a la representacion de los ValorOz sin ligar
	*/
	return (infoVar(name) != "_");
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

	return it != almacen.end();

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

list<string> Almacen :: getListVar(){
	list<string> vars;
	map<string, ValorOz*>::iterator it;

	for(it = almacen.begin(); it != almacen.end(); it++){
		vars.push_back( it->first );
	}

	return vars;
}

void Almacen :: showVarList(){
	list<string> vars = getListVar();

	list<string>::iterator it;

	for(it = vars.begin(); it != vars.end(); it++)
		cout << *it << "\n";
}

bool Almacen :: linkRec( ValorOz* v1, ValorOz* v2 ){
	map<string, ValorOz*>::iterator it1;
	map<string, ValorOz*>::iterator it2;
	map<string, ValorOz*> recAlmacen1 = ((ValorOzRec*)v1)->getMap();
	map<string, ValorOz*> recAlmacen2 = ((ValorOzRec*)v2)->getMap();
	map<string, string> aux;
	string c1, c2;
	Operacion o;

	for(it1 = recAlmacen1.begin(), it2 = recAlmacen2.begin() ; it1 != recAlmacen1.end(); it1++, it2++){
		c1 = infoVal( it1->second );
		c2 = infoVal( it2->second );

		if( o.evalType(c1) == "rec" && o.evalType(c2) == "rec" ){
			linkRec( it1->second, it2->second );
		}else{
			addVal(c1, c2);
		}

		if( getFail() )
			return false;

		if( getTwoLevelLink() ){
			keepTwoLevel();
			swapTwoLevelLink();
		}

	}
	return true;
}
