FLAGS=-pedantic -Wall -Werror -Wno-sign-compare -Wno-long-long -lm -pthread
COMPILLER=g++

all: start

start: libvector.so main.o main-dynam.o
	$(COMPILLER) $(FLAGS) -o os-lab5 main.o -L. -lvector -Wl,-rpath,.
	$(COMPILLER) $(FLAGS) -o os-lab5-dynam main-dynam.o -ldl

main.o: main.cpp
	$(COMPILLER) -c $(FLAGS) main.cpp

main-dynam.o: main-dynam.cpp
	$(COMPILLER) -c $(FLAGS) main-dynam.cpp

vector.o: vector.cpp
	$(COMPILLER) -c -fPIC $(FLAGS) vector.cpp

libvector.so: vector.o
	$(COMPILLER) $(FLAGS) -shared -o libvector.so vector.o

clear:
	-rm -f *.o *.gch *.so os-lab5
