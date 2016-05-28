#include "prim.h"
int main(int argc, char* argv[])
{
	int number_vertices=0;

	printf("\nPrim Algorithm\n");
	FILE *fp;
	if(argc!=2){
		printf("\n\nInvalid number of arguments!");
		exit(0);
	}
	fp = fopen(argv[1],"r");

  	int ch=0;
	if (fp == NULL)
	{
		perror("Error opening file");
       return(-1);
	}

  	number_vertices++;
  	while ((ch = fgetc(fp)) != EOF)
    {

      if (ch == '\n')
    	number_vertices++;
    }
  	fclose(fp);
	fp = fopen(argv[1] , "r");
    if(fp == NULL)
    {
       perror("Error opening file");
       return(-1);
    }
    // to read from text file
    int cn=0;
    int row=0;
    int col=0;
    int i=0;
    const char s[2] = ", ";
    char *token;
    if(fp != NULL)
    {
        char line[200];
        while(fgets(line, sizeof line, fp) != NULL)
        {
            token = strtok(line, s);
            for(i=0;i<number_vertices;i++)
            {
                    if(col<number_vertices)
        			{
           	 				weight[row][col]=atoi(token);
           	 				col++;
        			}
     				else
     				{
     						col=0;
      						row++;
      						weight[row][col]=atoi(token);
           	 				col++;
      				}
                    token = strtok(NULL,s);
            }
        }
        fclose(fp);
    }
	n=number_vertices;
	int j,ed,sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t", weight[i][j]);
		}
	}
	int count=0;
	int min,k,v1=0,v2=0;
	priority_queue[0]=0;
	while(count<n-1)
	{
		min=INF;
		for(i=0;i<=count;i++)
		for(j=0;j<n;j++)
		if(weight[priority_queue[i]][j]<min && !check(j,count))
		{
			min=weight[priority_queue[i]][j];
			v1=priority_queue[i];
			v2=j;
		}
		min_weights[v1][v2]=min_weights[v2][v1]=min;
		count++;
		priority_queue[count]=v2;
	}
        //To print list of edges
	printf("\n\n\nLIST OF EDGES\n");
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(i==j || min_weights[i][j]==0)
			{
				continue;
			}
			else
			{
				printf("\nEdge: %d ------ %d = %d ",i,j,min_weights[i][j]);
				sum+=min_weights[i][j];
			}
		}
	}
	printf("\n\nTotal Weight of a minimum spanning tree : %d\n",sum);
return 0;
}
