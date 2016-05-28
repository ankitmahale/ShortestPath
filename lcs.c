#include "lcs.h"
int main(int argc, char *argv[])
{
               char string1[20],string2[20];
               
               FILE *file_pointer = fopen ( argv[1], "r" );
               int i=0,k=0;
               memset(string1,'\0', sizeof(string1));
               memset(string2,'\0', sizeof(string2));
               if ( file_pointer != NULL )
               {
                  char line [128];

                  if ( fgets ( line, sizeof line, file_pointer ) != NULL )
                  {         // scan first string
                            for(i=0;i<strlen(line);i++)
                            {
                                  string1[i]=line[i];
                            }
                            string1[i]='\0';


                  }
                  if (fgets(line, sizeof line, file_pointer ) != NULL ) /* read a line */
                  {
                           // scan second string  
			   for(i=0;i<strlen(line);i++)
                            {
                                  string2[i]=line[i];
                            }
                            string2[i]='\0';

                  }
                  fclose ( file_pointer );
               }

                printf("\nThe Longest Common Subsequence between \n  %s  %s \n  is \n  ",string1,string2);
                least_common_sub(string1,string2);
                output(s1_size,s2_size,string1);
                
                printf("\n");
                // To find length of LCS
                printf("\nLength of the LCS is %d",length-2);
                if(length-2==0)
                printf("\nString is empty");
                printf("\n");
        return 0;
}
