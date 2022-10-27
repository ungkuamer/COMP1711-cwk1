
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sliceString(char *str, int start, int end) 
{

  int i;
  int size = (end - start) + 2;
  char *output = (char *)malloc(size * sizeof(char));

  for (i=0; start <= end; start++, i++) 
  {
    output[i] = str[start];
  }

  output[size] = '\0'

  return output;re

}

int main( int argc, char **argv ) 
{

  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char *filename;

  if ( argc > 1) 
  {

    filename = argv[1];
    fp = fopen(filename, "r");

    if (fp == NULL) 
    {
      printf("Input file does not exist. Exiting.\n");
      exit(0);
    }
  
    printf("Input file. Opening.\n"); 
    while ((read = getline(&line, &len, fp)) != -1) 
    {
      printf("%s", line);

    }

    printf("Input file. Closing.\n");
    fclose(fp);

  }

  else 
  {
    printf("No input file name given. Exiting.\n");
  }



  

  // reading from file
   
  
  
  

  // data processing
  //printf("Checking data.\n");
  //printf("Found an invalid student id: %d. Exiting.\n",id); // requires student id
  //printf("Correcting student %d grade %d\n",id,grade); // requires student id and relevant grade

  // compute averages
  //printf("Computing averages.\n");

  // writing to file
  //printf("Output file. Opening.\n");
  //printf("Output file. Closing.\n");

  return 0;
}

