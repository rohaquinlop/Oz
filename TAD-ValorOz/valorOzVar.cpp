#include "valorOzVar.h"
#include "valorOz.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...

ValorOzVar :: ValorOzVar(string _type, string _var) : ValorOz(_type){
	this->var = _var;
}

string ValorOzVar :: getVal(){
	return this->var;
}

void ValorOzVar :: setVar(string _var){
	this->var = _var;
}
