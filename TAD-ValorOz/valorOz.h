#ifndef VALOROZ_H
#define VALOROZ_H

//Importar las librerias necesarias
#include <iostream>
#include <string>
#include <map>

using namespace std;

class ValorOz{
    private:
        //Atributos
        string type;
        //Por medio de herencia se deben de crear los demas valores Oz que faltan
        //cada uno seria de la siguiente manera:
        //      ValorOzUnlinked, ValorOzInt, ValorOzFloat, ValorOzVar, ValorOzRec.
        //Nota: Implementar los registros, un registro es un mapa de strings, hacia valorOz
        //de esta manera se logra la "recursividad" para que un registro pueda tener sub-registros

    public:
        //Constructor, metodos: set, get
        ValorOz(string _type);
        void setType(string _type);
        string getType();
};

class ValorOzUnlinked : public ValorOz{
    private:
        //Atributo de la clase
        string val;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzUnlinked(string _val);
};

class ValorOzInt : public ValorOz{
    private:
        int val;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzInt(int _val);
        void setVal(int _val);
        int getVal();
};

class ValorOzFloat : public ValorOz{
    private:
        double val;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzFloat(double _val);
        void setVal(double _val);
        double getVal();
};

class ValorOzVar : public ValorOz{
    private:
        string var;
    public:
        //Constructor de la clase, metodos set y get
        ValorOzVar(string _var);
        void setVal(string _var);
        string getVal();
};

class ValorOzRec : public ValorOz{
    private:
        string name;
        map<string, ValorOz> m;
    public:
        //Constructor de la clase, metodos set y get.
        ValorOzRec(string _name, map<string, ValorOz> _m);
        void setName(string _name);
        void setMap(map<string, ValorOz> _m);
        string getName();
        map<string, ValorOz> getMap();
};

#endif
