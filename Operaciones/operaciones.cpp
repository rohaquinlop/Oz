#include "operaciones.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

//Métodos, set, get, constructores...
map<string, string> Operaciones :: parse(string _s){
	/*
	Operacion que evalua un string que ingresa, y determina
	cada campo que hay en el string.
	Ejemplo:
		- X=10 |--> c1 = X y c2 = 10
	*/
	map<string, string> fields;
	string c1 = "", c2 = "";
	int i;

	for(i = 0; i < _s.size(); i++){
		if( _s[i] == '=' ){
			i++;
			break;
		}else{
			c1 += _s[i];
		}
	}

	for(i; i < _s.size(); i++){
		c2 += _s[i];
	}

	fields["c1"] = c1;
	fields["c2"] = c2;

	return fields;

}