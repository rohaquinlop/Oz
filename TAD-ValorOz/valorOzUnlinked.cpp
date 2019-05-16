#include "valorOzUnlinked.h"
#include "valorOz.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...

ValorOzUnlinked :: ValorOzUnlinked(string _type, string _val) : ValorOz(_type){
	this->val = _val;
}

string ValorOzUnlinked :: getVal(){
	return "_";
}