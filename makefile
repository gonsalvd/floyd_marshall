all: Floyd-Warshall

Floyd-Warshall: fwarshall_main.o floyd_warshall.o
	g++ -g -std=c++0x -o Floyd-Warshall floyd_warshall.o fwarshall_main.o

fwarshall_main.o: fwarshall_main.cpp floyd_warshall.h
	g++ -c fwarshall_main.cpp

floyd_warshall.o: floyd_warshall.cpp floyd_warshall.h
	g++ -c floyd_warshall.cpp

clean:
	rm -rf *.o
	rm -rf Floy-Warshall
