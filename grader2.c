#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sliceString(char *str, int start, int end) // string slicing function
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

int main(int argc, char **argv)
{
	FILE *fp, *fp1;
	char *filename, line[100];
	float average, grades, current_num, frac_part, current_total;
	int i, count, student_id, int_part, final_result, printed_num, num_student;

	if (argc == 4) // checks if all argument is given
	{
		num_student = atoi(argv[1]);
		grades = atoi(argv[2]);
		filename = argv[3];

		int final_array[num_student][2];

		
		fp = fopen(filename, "r");

		if (fp == NULL) // checks if file exists
		{
			printf("Input file does not exist. Exiting.\n");
			exit(0);
		}

		if (num_student < 1 || num_student > 100) // checks for student range
		{
			printf("Requires 1 to 100 students. Exiting.\n");
			exit(0);
		}

		if (grades < 1 || grades > 8) // checks for grade range
		{
			printf("Requires 1 to 8 grades. Exiting.\n");
			exit(0);
		}

		printf("Input file. Opening.\n");
		printf("Input file. Closing.\n");

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
			for (i = 0; (i < grades); ++i)
			{
				current_num = atoi(sliceString(line, 8+(3*i), 10+(3*i)));

				if (current_num < 0 || current_num > 99)
				{
					if (current_num == -1)
					{
						current_num = 0;
					}
					else
					{
						printed_num = (int)current_num;
						printf("Found an invalid grade: id %d grade %d. Exiting.\n", student_id, printed_num);
						exit(0);
					}
				}

				if (current_num < 20 && current_num > 0)
				{
					printed_num = (int)current_num;
					printf("Correcting student %d grade %d\n", student_id, printed_num);
					current_num = 20;
				}

				if (current_num > 90 && current_num > 0)
				{
					printed_num = (int)current_num;
					printf("Correcting student %d grade %d\n", student_id, printed_num);
					current_num = 90;
				}

				current_total = current_total + current_num;				
			}

			average = current_total/grades;
			int_part = (int)average;
			frac_part = average - int_part;

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

		printf("Checking data.\n");
		printf("Computing averages.\n");
		printf("Output file. Opening.\n");
		fp1 = fopen("averages.txt", "w");
		for (i = 0; (i < num_student); ++i)
		{
			fprintf(fp1, " %i %i\n", final_array[i][0], final_array[i][1]);
		}

		fclose(fp);
		fclose(fp1);
		printf("Output file. Closing.\n");

	}

	else
	{
		printf("Incorrect arguments given. Expecting nStudents nGrades fileName. Exiting.\n");
		exit(0);
	}

	return 0;
}