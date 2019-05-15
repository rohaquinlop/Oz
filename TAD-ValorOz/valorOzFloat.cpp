#include "valorOzFloat.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...
valorOzFloat :: valorOzFloat(double _val){
	val = _val;
}

string valorOzFloat :: getVal(){
	string value = to_string(val);
	return value;
}