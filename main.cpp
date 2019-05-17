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
	Almacen a;
	ValorOz* v;

	v = new ValorOzInt("int", 10);

	a.addVal("X", v);

	a.showInfo();

    return 0;
}
