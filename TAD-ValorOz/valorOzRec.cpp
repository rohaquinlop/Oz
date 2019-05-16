#include "valorOzRec.h"
#include "valorOz.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

//Métodos, set, get, constructores...
ValorOzRec :: ValorOzRec(string _type, string _name, map<string, ValorOz> _m) : ValorOz(_type){
	this->name = _name;
	this->m = _m;
}

/*
string ValorOzRec :: getval(){
	//Falta implementar
}
*/