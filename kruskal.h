#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED
#include <stdio.h>
#include<stdlib.h>
#include<sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cstdlib>
#include<vector>
using namespace std;

//Edge structure.
struct Edge
{
    int src, dest, weight;
};

// A structure to represent a subset for union-find.
struct subset
{
    int parent;
    int rank;
};

//Generated adj matrix with random values.
void gen_adj_matrix(vector< vector<int> > &adj, int number_of_vertices,char *argv[]){


	//Generate random value. and fill in the adj list.
  FILE *fp;
  fp = fopen(argv[1],"r");
int cn=0;
    int row=0;
    int col=0;
    int i=0;
    const char s[2] = ",";
    char *token;
    if(fp != NULL)
    {
        char line[200];
        while(fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, s);
            for(i=0;i<number_of_vertices;i++)
            {
                    if(col<number_of_vertices)
        			{
           	 				adj[row][col]=atoi(token);
           	 				col++;
        			}
     				else
     				{
     						col=0;
      						row++;
      						adj[row][col]=atoi(token);
           	 				col++;
      				}
                    token = strtok(NULL,s);
            }
        }
        fclose(fp);
    }

}

//Print the adj matrix.
void printMatrix(vector< vector<int> > &adj, int number_of_vertices){
	int i=0, j=0;

	//print the adj matrix.
	for(i=0;i<number_of_vertices;i++){
		printf("\n");
		for(j=0;j<number_of_vertices;j++){
			printf("%5d", adj[i][j]);
		}
	}
}

//Sort the edges of graph, from adj matrix.
void storeSortedEdges(vector< struct Edge > &sorted_edges, vector< vector<int> > &adj, int number_of_vertices){
	int i=0,j=0,k=0;

	//Clear the vector to store sorted edges.
	sorted_edges.clear();

	//Put edges in vector.
	for(i=0;i<number_of_vertices;i++){
		for(j=0;j<number_of_vertices;j++){
			sorted_edges[k].src = i;
			sorted_edges[k].dest = j;
			sorted_edges[k].weight = adj[i][j];
			k++;
		}
	}

	//Sort the edges according to weight.
	for(int j=1;j<k;j++){
        for(int i=0; i<k; i++){
            if(sorted_edges[i].weight > sorted_edges[i+1].weight){
            	Edge temp = sorted_edges[i];
                sorted_edges[i] = sorted_edges[i+1];
                sorted_edges[i+1] = temp;
            }
        }
    }


}

// A utility function to find set of an element i
// (uses path compression technique).
int find(struct subset part[], int i)
{
    // find root and make root as parent of i (path compression).
    if (part[i].parent != i)
        part[i].parent = find(part, part[i].parent);

    return part[i].parent;
}

// A function that does union of two sets of x and y
// (uses union by rank).
void Union(struct subset part[], int x, int y)
{
    int parent = find(part, x);
    int parent1 = find(part, y);

    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank).
    if (part[parent].rank < part[parent1].rank)
        part[parent].parent = parent1;
    else if (part[parent].rank > part[parent1].rank)
        part[parent1].parent = parent;

    // If ranks are same, then make one as root and increment
    // its rank by one.
    else
    {
        part[parent1].parent = parent;
        part[parent].rank++;
    }
}

//Kruskal's greedy algorithm.
void kruskal_perform(vector< struct Edge > &sorted_edges, vector< vector<int> > &adj, int number_of_vertices){
	struct Edge result[number_of_vertices];

	// Allocate memory for creating V part
    struct subset *part =
        (struct subset*) malloc( number_of_vertices * sizeof(struct subset) );

    // Create number_of_vertices part with single elements
    for (int v = 0; v < number_of_vertices; ++v)
    {
        part[v].parent = v;
        part[v].rank = 0;
    }

    int i=0, e=0;

	// Number of edges to be taken is equal to number_of_vertices-1
    while (e < number_of_vertices - 1)
    {
        // Pick the smallest edge. And increment the index
        // for next iteration
        struct Edge n_edge = sorted_edges[i++];

 		//Find sets of src and dest.
        int x = find(part, n_edge.src);
        int y = find(part, n_edge.dest);

        // If including this edge does't cause cycle, include it
        // in result and increment the index of result for next edge
        if (x != y)
        {
            result[e++] = n_edge;
            Union(part, x, y);
        }
        // Else discard the n_edge
    }

    // print the contents of result[] to display the built MST
    int sum=0;
    printf("\nEdges in the constructed MST:");
    for (i = 0; i < e; ++i)
    {
        printf("\nEdge of (%d)(%d) = %d", result[i].src, result[i].dest, result[i].weight);
        sum=sum+result[i].weight;
    }
    printf("\nWeight of the minimum spanning tree is %d",sum);
}


#endif // KRUSKAL_H_INCLUDED
