FLAGS = -g -Wall -pedantic

all: main.cpp bmp.cpp lib/lib.a
		g++ $(FLAGS) bmp.cpp lib/lib.a -o main

lib/lib.a: lib/image.hpp lib/image.cpp lib/bmp.hpp lib/bmp.cpp
		g++ $(FLAGS) -c lib/image.cpp -o lib/image.o
		g++ $(FLAGS) -c lib/bmp.cpp -o lib/bmp.o
		ar -r lib/lib.a lib/image.o lib/bmp.o

clean: 
		rm -f main lib/lib.a lib/*.o