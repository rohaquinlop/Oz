#include "operacion.h"
#include <iostream>
#include <string>
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

	for(i = 0; i < s.size(); i++){
		if( s[i] == '=' ){
			i++;
			break;
		}else{
			c1 += s[i];
		}
	}

	for(i; i < s.size(); i++){
		c2 += s[i];
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

	if ( it != s.end() )
		return false;

	return true;
}

string Operacion :: evalType(string s){
	/*
	Funcion que retorna el tipo de variable que se ingreso
    Tipos: record, var, int, float, unLinked
      registro está escrito en minuscula.
      variable está escrita en MAYUSCULA.
      int no tiene un '.'
      float tiene un '.'
      unLinked es igual a _
	*/
	if ( s == "_" ){
		return "unLinked";
	}else if( s[0] >= 'A' || s[0] <= 'Z' ){
		return "var";
	}else if( s[0] >= 'a' || s[0] <= 'z' ){
		return "rec";
	}else if( isInt(s) ){
		return "int";
	}
	return "float";
}