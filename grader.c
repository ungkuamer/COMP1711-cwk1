#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// string slicing function
char *sliceString(char *str, int start, int end)
{

	int i;
	int size = (end - start) + 2;
	char *output = (char *)malloc(size * sizeof(char));

	for (i = 0; start <= end; start++, i++)
	{
		output[i] = str[start];
	}

	output[size] = '\0';

	return output;
}

// main function
int main(int argc, char **argv)
{

	FILE *fp, *fp1;
	char *filename, line[100]; 
	float average, current_num, frac_part, current_total;
	int i, count, student_id, int_part, final_result, printed_num, final_array[32][2];

	if (argc == 2) // checks for command line argument
	{
		filename = argv[1];
		count = 0;

		fp = fopen(filename, "r"); // returns null if file not exist
		
		fp1 = fopen("averages.txt", "w");

		if (fp == NULL)
		{
			printf("Input file does not exist. Exiting.\n");
			exit(0);
		}
		printf("Input file. Opening.\n");
		
		printf("Checking data.\n");
		printf("Computing averages.\n");

		while (!feof(fp)) // while not end of file 
		{
			fgets(line, 100, fp);
			student_id = atoi(sliceString(line, 0, 7));

			if (student_id < 2022000 || student_id > 2022099) // checks student id range
			{
				printf("Found an invalid student id: %d. Exiting.\n", student_id);
				exit(0);
			}

			current_total = 0;

			for (i = 0; i < 4; ++i)
			{
				current_num = atoi(sliceString(line, 8+(3*i), 10+(3*i)));

				if (current_num < 0 || current_num > 99) // checks grade range
				{
					printed_num = (int)current_num;
					printf("Found an invalid grade: id %d grade %d. Exiting.\n", student_id, printed_num);
					exit(0);
				}

				if (current_num < 20) // correcting grades
				{
					printed_num = (int)current_num;
					printf("Correcting student %d grade %d\n", student_id, printed_num);
					current_num = 20;
				}

				if (current_num > 90) // correcting grades
				{
					printed_num = (int)current_num;
					printf("Correcting student %d grade %d\n", student_id, printed_num);
					current_num = 90;
				}

				current_total = current_total + current_num;
			}

			
			average = current_total/4;
			int_part = (int)average;
			frac_part = average - int_part;

			// rounding off
			if (frac_part < 0.5)
			{
				final_result = int_part;
			}

			if (frac_part >= 0.5)
			{
				final_result = int_part + 1;
			}

			final_array[count][0] = student_id;
			final_array[count][1] = final_result;

			count = count + 1;
		}

		for (i = 0; i < 32; ++i)
		{
			fprintf(fp1, " %i %i\n", final_array[i][0], final_array[i][1]);
		}
		printf("Output file. Opening.\n");
		printf("Input file. Closing.\n");
		printf("Output file. Closing.\n");
		fclose(fp);
		fclose(fp1);

	}

	else
	{
		printf("No input file name given. Exiting.\n");
		exit(0);
	}

	return 0;
}