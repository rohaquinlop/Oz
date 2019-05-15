#include "valorOzVar.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...

valorOzVar :: valorOzVar(string _var){
	var = _var;
}

string valorOzVar :: getVal(){
	return var;
}
