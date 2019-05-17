#ifndef OPERACION_H
#define OPERACION_H

//Importar las librerias necesarias

#include <iostream>
#include <map>

using namespace std;

class Operacion{
    public:
        //Metodos
        map<string, string> parse(string s);
        bool isInt(string s);
        string evalType(string s);
};

#endif
