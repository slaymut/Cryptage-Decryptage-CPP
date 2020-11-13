cc=g++
CFLAGS= -std=c++17 

all : Main.out 

Main.out : Main.cpp ArbreB.cpp Sommet.cpp 
		$(cc) -o Main.out Main.cpp ArbreB.cpp Sommet.cpp $(CFLAGS)

clean : 
		rm -rf *.out