#include "kruskal.h"
int main(int argc, char *argv[]){
	int number_of_vertices = 0;


   unsigned int number_of_lines = 0;
    FILE *infile = fopen(argv[1], "r");
    int ch;

    while (EOF != (ch=getc(infile)))
        if ('\n' == ch)
            ++number_of_lines;

   number_of_vertices=number_of_lines+1;
   fclose(infile);


	//Vector for sorted edges.
	int edges= number_of_vertices*number_of_vertices;

    vector<struct Edge> sorted_edges (edges);

	printf("\nThe number of vertices are: %d", number_of_vertices);


	vector<int> inner (number_of_vertices);
    vector< vector<int> > adj(number_of_vertices, inner);


    gen_adj_matrix(adj, number_of_vertices,argv);

    printf("\nThe adjancency matrix generated is:");
    printMatrix(adj, number_of_vertices);
    storeSortedEdges(sorted_edges, adj, number_of_vertices);
    kruskal_perform(sorted_edges, adj, number_of_vertices);

	return 0;
}

