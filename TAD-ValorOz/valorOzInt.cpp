#include "valorOzInt.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...
valorOzInt :: valorOzInt(int _val){
	val = _val;
}

string valorOzInt :: getVal(){
	string value = to_string(val);
	return value;
}