#include "operacion.h"
#include "../TAD-ValorOz/valorOz.h"
#include "../TAD-ValorOz/valorOzFloat.h"
#include "../TAD-ValorOz/valorOzInt.h"
#include "../TAD-ValorOz/valorOzRec.h"
#include "../TAD-ValorOz/valorOzUnlinked.h"
#include "../TAD-ValorOz/valorOzVar.h"
#include "../TAD-Almacen/almacen.h"
#include <iostream>
#include <string>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

//Métodos, set, get, constructores...
map<string, string> Operacion :: parse(string s){
	/*
	Operacion que evalua un string que ingresa, y determina
	cada campo que hay en el string.
	Ejemplo:
		- X=10 | ---> | c1 = X y c2 = 10
	*/
	map<string, string> fields;
	string c1 = "", c2 = "";
	int i;
	bool found = false;

	for(i = 0; i < s.size(); i++){
		if( s[i] == '=' && !found ){
			found = true;
		}else if( found ){
			c2 += s[i];
		}else if( !found ){
			c1 += s[i];
		}
	}

	fields["c1"] = c1;
	fields["c2"] = c2;

	return fields;
}

map<string, string> Operacion :: parseRec(string s){
	/*
	Operacion que evalua un string que ingresa, y determina
	cada campo que hay en el string.
	Ejemplo:
		- X=10 | ---> | c1 = X y c2 = 10
	*/
	map<string, string> fields;
	string c1 = "", c2 = "";
	int i;
	bool found = false;

	for(i = 0; i < s.size(); i++){
		if( s[i] == ':' && !found ){
			found = true;
		}else if( found ){
			c2 += s[i];
		}else if( !found ){
			c1 += s[i];
		}
	}

	fields["c1"] = c1;
	fields["c2"] = c2;

	return fields;
}

bool Operacion :: isInt(string s){
	/*
	Operacion que retorna true si el string ingresado es un entero
	o false si es un numero flotante.
	*/
	
	string::iterator it;
	it = find(s.begin(), s.end(), '.');

	return it == s.end();
}

string Operacion :: evalType(string s){
	/*
	Funcion que retorna el tipo de variable que se ingreso
    Tipos: record, var, int, float, unLinked
      registros y campos están escritos en minusculas.
      variable está escrita en MAYUSCULA.
      int no tiene un '.'
      float tiene un '.'
      unLinked es igual a _
	*/
	if ( s == "_" ){
		return "unLinked";
	}else if( s[0] >= 'A' && s[0] <= 'Z' ){
		return "var";
	}else if( s[0] >= 'a' && s[0] <= 'z' ){
		for(int i = 0 ; i < s.size(); i++){
			if( s[i] == '(' ){
				return "rec";
			}
		}
		return "camp";
	}else if( isInt(s) ){
		return "int";
	}
	return "float";
}

ValorOz* Operacion :: buildValorOz(string _type, string _val){
	/*
	Esta funcion crea un valor Oz dependiendo del tipo que recibe como parametro
	de esta forma verifica el tipo, llama el constructor de la clase en especifico,
	lo construye y lo retorna
	*/
	ValorOz* v;
	std::string::size_type sz;
	if( _type == "unLinked" ){
		v = new ValorOzUnlinked(_type, _val);
	}else if( _type == "int" ){
		v = new ValorOzInt(_type, stoi(_val) );
	}else if( _type == "float" ){
		v = new ValorOzFloat(_type, stod(_val, &sz) );
	}else if( _type == "var" ){
		v = new ValorOzVar(_type, _val);
	}

	return v;
}

ValorOz* Operacion :: buildValRec(string _type, string _val){
	int i, open = 0;
	string name = "", subVal = "";
	Almacen a;
	ValorOz* v;
	stack<string> subVals;

	for(i = 0; i < _val.size(); i++){
		if( _val[i] == '(' ){
			i++;
			break;
		}
		name += _val[i];
	}

	for(i; i < _val.size(); i++){
		if( _val[i] == ' ' && open == 0){
			subVals.push(subVal);
			subVal = "";
		}else{
			if( open > 0 ){
				subVal += _val[i];

				if( _val[i] == ')' )
					open--;

				if( _val[i] == '(' )
					open++;

			}else{
				if( _val[i] == '(' )
					open++;
				if( _val[i] != ')' )
					subVal += _val[i];
			}
		}
	}
	if(subVal.size() >= 3)
		subVals.push(subVal);

	while( !subVals.empty() ){
		subVal = subVals.top();
		subVals.pop();
		a.addVal( parseRec( subVal ) );
	}

	v = new ValorOzRec( _type, name, a.getAlmacen() );
	return v;

}

bool Operacion :: compareRec( ValorOz* v, ValorOz* cmp ){
	return ((ValorOzRec*)v)->getCamps() == ((ValorOzRec*)cmp)->getCamps();
}