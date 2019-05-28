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

int main(){
	Operacion operacion;
	Almacen almacen;
	string line;
	map<string, string> m;

	while( getline(cin, line) ){
		m = operacion.parse( line );
		almacen.addVal( m["c1"], m["c2"] );

		if( almacen.getTwoLevelLink() ){
			almacen.keepTwoLevel();
			almacen.swapTwoLevelLink();
		}

		if( almacen.getFail() ){
      		cout << "La ligadura ingresada no es permitida: " << line <<"\n";
      		break;
    	}
	}

	almacen.showInfo();

    return 0;
}
