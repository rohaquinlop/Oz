#ifndef VALOROZ_H
#define VALOROZ_H

//Importar las librerias necesarias
#include <iostream>
#include <string>

using namespace std;

class ValorOz{
    private:
        //Atributos
        string type;
        //Por medio de herencia se deben de crear los demas valores Oz que faltan
        //cada uno seria de la siguiente manera:
        //      ValorOzUnlinked, ValorOzInt, ValorOzFloat, ValorOzVar, ValorOzRec.
        //Nota: Implementar los registros, un registro es un mapa de strins, hacia valorOz, de esta manera se logra la "recursividad" para que un registro pueda tener sub-registros

    public:
        //Constructor, metodos: set, get
        ValorOz(string _type);
        setType(string _type);
        string getType();
};

#endif
