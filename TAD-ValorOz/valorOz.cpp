#include "valorOz.h"
#include <iostream>
#include <string>

using namespace std;

//Métodos, set, get, constructores...

ValorOz :: ValorOz(string _type){
	type = _type;
}

string ValorOz :: getType(){
	return type;
}
