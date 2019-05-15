# Oz - Estructuras semánticas
## Proyecto Final Estructuras de Datos
### Pontificia Universidad Javeriana Cali 2019-1
## Autores:
* Robin Quintero.
* Jhon Londoño.
* Kevin Ocampo.

## Objetivos
* Diseño e implementación de Tipos Abstractos de Datos.
* Análisis de la complejidad computacional de la implementación de operaciones primitivas de un Tipo Abstracto de Dato.
* Análisis y comparación en términos de complejidad computacional de diferentes estrategias de representación para un mismo Tipo Abstracto de Dato.
* Diseño e implementación de operaciones generales sobre un Tipo Abstracto de Dato.

## To-Do List
* ~~Mantener la ligadura de las variables a un solo nivel (Entrada)~~
* Implementar los registros o "records". (**Arbol**)
* Implementar funcion que verifique el nivel de las variables en el almacen para mantener el árbol en dos niveles.

## Notas del proyecto
* Hasta ahora hace la ligadura y mantiene el arbol a 2 niveles desde el nodo padre hasta los nodos hijos cuando apuntan hacia el, sin embargo, esto solo sucede cuando las variables son creadas previamente y se hace desde el mas viejo al mas nuevo. Ejemplo:
```
Ambos casos son diferentes
Primer caso
Entrada:
X=_
Y=_
Z=_
Y=X
Z=Y
A=Z

Almacen:
X -> _
Y -> X
Z -> X
A -> X

Segundo caso
Entrada:
X=_
Y=_
Z=_
A=Z
Z=Y
Y=X

Almacen:
X -> _
Y -> X
Z -> Y
A -> Z

Lo ideal es que se quedaran las variables como en el primer caso y no como se ve en el segundo almacen.
```
