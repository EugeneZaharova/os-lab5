FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -pthread
COMPILLER=g++

all: start

start: vector.o main.o
	$(COMPILLER) $(FLAGS) -o os-lab5 vector.o main.o

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

vector.o: vector.cpp
	$(COMPILLER) -c $(FLAGS) vector.cpp

clear:
	-rm -f *.o *.gch os-lab5
