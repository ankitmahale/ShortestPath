#ifndef PRIM1_H_INCLUDED
#define PRIM1_H_INCLUDED

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INF 999
int weight[10][10];
int min_weights[10][10];
int priority_queue[10];
int n;
int check(int i, int n1)
{
        int j;
	for(j=0;j<=n1;j++)
	{
		if(priority_queue[j]==i)
			return 1;
	}
	return 0;
}


#endif // PRIM1_H_INCLUDED
