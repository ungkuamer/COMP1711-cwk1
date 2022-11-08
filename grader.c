
/*
 * Template file for the solution to part 1
 * Use the included print statements in your code at appropriate times.
 * Do not adjust the format of the print statements.
 * Do not submit a final solution with additional print statements.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sliceString(char *str, int start, int end) // string slicing function
{

  int i;
  int size = (end - start) + 2;
  char *output = (char *)malloc(size * sizeof(char));

  for (i=0; start <= end; start++, i++) 
  {
    output[i] = str[start];
  }

  output[size] = '\0';

  return output;

}

int main( int argc, char **argv ) 
{

  FILE *fp;
  FILE *fp1;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;
  char *filename;
  float grade1, grade2, grade3, grade4, average, frac_part;
  int studentId, int_part, final_result, count, i, final_array[32][2];

  if ( argc > 1) // checks if there is a command line argument
  {

    filename = argv[1];
    fp = fopen(filename, "r"); // returns a null if file not exist

    if (fp == NULL)
    {
      printf("Input file does not exist. Exiting.\n");
      exit(0);
    }
  
    printf("Input file. Opening.\n");
    printf("Output file. Opening.\n");
    printf("Computing averages.\n");

    count = 0;
    fp1 = fopen("averages.txt", "w"); 
    while ((read = getline(&line, &len, fp)) != -1) // reading each line from the file
    {

      grade1 = atoi(sliceString(line,8,10));
      grade2 = atoi(sliceString(line,11,13));
      grade3 = atoi(sliceString(line,14,16));
      grade4 = atoi(sliceString(line,17,19));
      studentId = atoi(sliceString(line,0,7));

      average = (grade1+grade2+grade3+grade4)/4;
      int_part = (int)average;
      frac_part = average - int_part;

      if (frac_part < 0.5) {
        final_result = int_part;
      }
      
      if (frac_part >= 0.5) {
        final_result = int_part + 1;
      }

      final_array[count][0] = studentId;
      final_array[count][1] = final_result;

      // fprintf(fp1,"%i %i\n",studentId, final_result);
      count = count + 1;
    }

    for (i = 0; i < 32; ++i)
    {
      fprintf(fp1, "%i %i\n", final_array[i][0], final_array[i][1]);
    }

    printf("Input file. Closing.\n");
    printf("Output file. Closing.\n");
    fclose(fp);
    fclose(fp1);

  }

  else 
  {
    printf("No input file name given. Exiting.\n");
  }

  return 0;
}

