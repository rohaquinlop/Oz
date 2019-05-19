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
	Almacen almacen;
	ValorOz* v;

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

    return 0;
}
