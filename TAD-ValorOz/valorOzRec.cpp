#include "valorOzRec.h"
#include "valorOz.h"
#include "../Operacion/operacion.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

//Métodos, set, get, constructores...
ValorOzRec :: ValorOzRec(string _type, string _name, map<string, ValorOz*> _m) : ValorOz(_type){
	this->name = _name;
	this->m = _m;
}

string ValorOzRec :: getVal(){
	stringstream ss;
	if( (this->m).size() == 0 ){
		ss << this->name;
		return ss.str();
	}else{
		int count = 0;
		ss << this->name << "(";
		map<string, ValorOz*>::iterator it;
		
		for( it = (this->m).begin(); it != (this->m).end(); it++ ){
			count++;
			ss << it->first << ":";
			if( (it->second)->getType() != "rec" ){
				if( (it->second)->getType() == "unLinked" ){
					ss << ((ValorOzUnlinked*)(it->second))->getVal();
				}
				else if( (it->second)->getType() == "int" ){
					ss << ((ValorOzInt*)(it->second))->getVal();
				}
				else if( (it->second)->getType() == "float" ){
					ss << ((ValorOzFloat*)(it->second))->getVal();
				}
				else if( (it->second)->getType() == "var" ){
					ss << ((ValorOzVar*)(it->second))->getVal();
				}
			}else
				ss << ((ValorOzRec*)(it->second))->getVal();
			if( count < (this->m).size() ){
				ss << " ";
			}
		}
		ss << ")";
	}

	return ss.str();

}

string ValorOzRec :: getCamps(){
	stringstream ss;
	if( (this->m).size() == 0 ){
		ss << this->name << "()";
		return ss.str();
	}else{
		int count = 0;
		ss << this->name << "(";
		map<string, ValorOz*>::iterator it;
		
		for( it = (this->m).begin(); it != (this->m).end(); it++ ){
			count++;
			ss << it->first;
			if( (it->second)->getType() == "rec" )
				ss << ((ValorOzRec*)(it->second))->getCamps();

			if( count < (this->m).size() )
				ss << " ";
		}
		ss << ")";
	}

	return ss.str();

}

map<string, ValorOz*> ValorOzRec :: getMap(){
	return this->m;
}