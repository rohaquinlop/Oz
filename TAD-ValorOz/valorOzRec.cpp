#include "valorOzRec.h"
#include "valorOz.h"
#include "../Operacion/operacion.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

//Métodos, set, get, constructores...
ValorOzRec :: ValorOzRec(string _type, string _name, map<string, ValorOz*> _m) : ValorOz(_type){
	this->name = _name;
	this->m = _m;
}

void ValorOzRec :: getVal(){
	if( (this->m).size() == 0 ){
		cout << this->name << "\n";
	}else{
		cout << this->name << "(";
		map<string, ValorOz*>::iterator it;
		
		for( it = (this->m).begin(); it != (this->m).end(); it++ ){
			cout << it->first << ":";
			if( (it->second)->getType() != "rec" ){
				if( (it->second)->getType() == "unLinked" ){
					cout << ((ValorOzUnlinked*)(it->second))->getVal();
				}
				else if( (it->second)->getType() == "int" ){
					cout << ((ValorOzInt*)(it->second))->getVal();
				}
				else if( (it->second)->getType() == "float" ){
					cout << ((ValorOzFloat*)(it->second))->getVal();
				}
				else if( (it->second)->getType() == "var" ){
					cout << ((ValorOzVar*)(it->second))->getVal();
				}
			}else
				((ValorOzRec*)(it->second))->getVal();
			cout << " ";
		}
		cout << ")";
	}

}