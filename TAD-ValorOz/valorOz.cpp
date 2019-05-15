#include "valorOz.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...

valorOz :: valorOz(string _type){
	type = _type;
}

string valorOz :: getType(){
	return type;
}
