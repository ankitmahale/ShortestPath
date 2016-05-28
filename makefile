all: prim.c prim.h kruskal.cpp kruskal.h lcs.c lcs.h
	gcc prim.c -o prim.out
	g++ kruskal.cpp -o kruskal.out
	gcc lcs.c -o lcs.out

clean:
	rm prim.out kruskal.out lcs.out graph.txt string.txt
