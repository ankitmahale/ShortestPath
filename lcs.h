#ifndef LCS1_H_INCLUDED
#define LCS1_H_INCLUDED
int length=0;
#include<stdio.h>
#include<string.h>
char string3[50][50];
int s1_size,s2_size,c[20][20];
//Function to find least common subsequence.
void least_common_sub(char *string1, char *string2)
{               int i,j;
                s1_size=strlen(string1);
                s2_size=strlen(string2);

                for(i=1;i<=s1_size;i++)
                    for(j=1;j<=s2_size;j++)
                     {
                        if(string1[i-1]==string2[j-1])
                        {
                            c[i][j]=c[i-1][j-1]+1;
                            string3[i][j]='k';
                        }
                        else if(c[i-1][j]>=c[i][j-1])
                        {
                            c[i][j]=c[i-1][j];
                            string3[i][j]='z';
                        }
                        else
                        {
                            c[i][j]=c[i][j-1];
                            string3[i][j]='x';
                        }

                    }
}
// to print the output to stdout
void output(int i,int j,char *string1)
{
                if(i==0 || j==0)
                                return;
                if(string3[i][j]=='k')
                {
                    output(i-1,j-1,string1);
                    printf("%c",string1[i-1]);
                    length++;
                }
                else if(string3[i][j]=='z')
                                output(i-1,j,string1);
                else
                                output(i,j-1,string1);
}














#endif // LCS1_H_INCLUDED
