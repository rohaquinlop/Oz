all:
	g++ main.cpp Operacion/*.cpp TAD-Almacen/*.cpp TAD-ValorOz/*.cpp -o a.out
	./a.out < input.txt > output.txt
