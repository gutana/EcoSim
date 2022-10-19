all : main

main.o : main.cpp EconomicEntity.h EconomicSimulation.h
	g++ -c -ggdb main.cpp

EconomicEntity.o : EconomicEntity.cpp EconomicEntity.h
	g++ -c -ggdb EconomicEntity.cpp

EconomicSimulation.o : EconomicSimulation.cpp EconomicSimulation.h
	g++ -c -ggdb EconomicSimulation.cpp
		
main : main.o functions.o
	g++ main.o EconomicEntity.o EconomicSimulation.o -o demo

check : all
	./main

clean : rm -f *.o main
