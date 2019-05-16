#include "valorOzFloat.h"
#include "valorOz.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...
ValorOzFloat :: ValorOzFloat(string _type, double _val) : ValorOz(_type){
	this->val = _val;
}

string ValorOzFloat :: getVal(){
	double aux = this->val;
	string value = to_string(aux);
	return value;
}