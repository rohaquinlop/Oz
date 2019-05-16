#include "valorOzInt.h"
#include "valorOz.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...
ValorOzInt :: ValorOzInt(string _type, int _val) : ValorOz(_type){
	this->val = _val;
}

string ValorOzInt :: getVal(){
	string value = to_string(this->val);
	return value;
}