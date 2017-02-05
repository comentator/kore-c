INC=-I./ -I../Kore/Sources -I../Kore/Backends/Linux/Sources -I../Kore/Backends/OpenGL2/Sources
LIB=-lkore -pthread -lasound -ldl -lGL -lX11 -lXinerama
DEF=-DOPENGL -DSYS_UNIXOID -DSYS_LINUX


# -no-hygiene -lflags -cclib,-lkore -lflags -cclib,-lkorec

Kore: main.o
	g++ -shared -o libkorec.so -O2 main.o

main.o: main.cpp
	g++ -O2 $(INC) $(DEF) -fPIC -c main.cpp -o main.o -L. $(LIB)
