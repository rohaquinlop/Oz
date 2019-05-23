#include "Operacion/operacion.h"
#include "TAD-Almacen/almacen.h"
#include "TAD-ValorOz/valorOz.h"
#include "TAD-ValorOz/valorOzFloat.h"
#include "TAD-ValorOz/valorOzInt.h"
#include "TAD-ValorOz/valorOzVar.h"
#include "TAD-ValorOz/valorOzRec.h"
#include "TAD-ValorOz/valorOzUnlinked.h"
#include <iostream>
#include <string>

using namespace std;

bool fail = false, twoLevelLink = false;

int main(){
	Operacion operacion;
	Almacen almacen;
	string line;
	map<string, string> m;

	while( getline(cin, line) ){
		m = operacion.parse( line );
		almacen.addVal( m );

		if( fail ){
      		cout << "La ligadura ingresada no es permitida: " << line <<"\n";
      		break;
    	}
	}
	if( twoLevelLink ){
		almacen.keepTwoLevel();
	}
	almacen.showInfo();


	/*

	v = new ValorOzInt("int", 10);

	almacen.addVal("X", v);

	v = new ValorOzVar("var", "X");

	almacen.addVal("Y", v);

	v = new ValorOzVar("var", "Y");

	almacen.addVal("Z", v);

	v = new ValorOzVar("var", "Z");

	almacen.addVal("W", v);

	almacen.showInfo();

	cout << "Padre de W -> " << almacen.findFather( v ) << "\n";
	*/

    return 0;
}
