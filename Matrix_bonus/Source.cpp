// 123   147
// 456   258
// 789   369

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	int const max_lines_number = 100;
	int const max_column_number = 100;

	int lines_number;
	int column_number;
	int matrix[max_lines_number][max_column_number];
	int choise;

	printf_s("Please, enter the number of lines that your matrix will consist of: ");
	scanf_s("%d", &lines_number);
	printf_s("Please, enter the number of column that your matrix will consist of: ");
	scanf_s("%d", &column_number);
	printf_s("Enter elements of the matrix:\n1-random\n2-by my own\n");
	scanf_s("%d", &choise);

	printf_s("\n");

	switch (choise)
	{
	case 1:
	{
		srand(time(NULL));
		for (int i = 0; i < lines_number; i++)
		{
			for (int j = 0; j < column_number; j++)
			{
				matrix[i][j] = -lines_number + rand() % column_number + 1;
			}
		}

		for (int i = 0; i < lines_number; i++)
		{
			for (int j = 0; j < column_number; j++)
			{
				printf_s("%d\t", matrix[i][j]);
			}
			printf_s("\n");
		}
	};
	break;
	case 2:
	{
		for (int i = 0; i < lines_number; i++)
		{
			for (int j = 0; j < column_number; j++)
			{
				printf_s("Enter [%d%d] element: ", i, j);
				scanf_s("%d", &matrix[i][j]);
			}
		}

		printf_s("\n");

		for (int i = 0; i < lines_number; i++)
		{
			for (int j = 0; j < column_number; j++)
			{
				printf_s("%d\t", matrix[i][j]);
			}
			printf_s("\n");
		}
	};
	break;
	default: printf_s("You are loser, who hasn't learned to read by his age(");
	};

	printf_s("\n");

	int choise_2;
	printf_s("Choise what you want to do:\n");
	printf_s("1-transpose matrix\n");
	printf_s("2-change line with max element with line that consist min element\n");
	printf_s("3-snake\n");
	scanf_s("%d", &choise_2);

	switch (choise_2)
	{
	case 1:
	{
		printf_s("\n");

		for (int j = 0; j < column_number; j++)
		{
			for (int i = 0; i < lines_number; i++)
			{
				printf_s("%d\t", matrix[i][j]);
			}
			printf_s("\n");
		}
	};
	break;
	case 2:
	{
		printf_s("\n");
		int max_element = INT_MIN;
		int min_element = INT_MAX;
		int line_index_max = 0;
		int line_index_min = 0;
		for (int i = 0; i < lines_number; i++)
		{
			for (int j = 0; j < column_number; j++)
			{
				if (matrix[i][j] > max_element)
				{
					max_element = matrix[i][j];
					line_index_max = i;
				}

				if (matrix[i][j] < min_element)
				{
					min_element = matrix[i][j];
					line_index_min = i;
				}

			}
		}

		int temp = 0;
		for (int j = 0; j < column_number; j++)
		{
			temp = matrix[line_index_min][j];
			matrix[line_index_min][j] = matrix[line_index_max][j];
			matrix[line_index_max][j] = temp;

		}

		for (int i = 0; i < lines_number; i++)
		{
			for (int j = 0; j < column_number; j++)
			{
				printf_s("%d\t", matrix[i][j]);
			}
			printf_s("\n");
		}
		printf_s("\n");

		printf_s("Max element: %d\n", max_element);
		printf_s("Line with max element: %d\n", line_index_max);
		printf_s("Min element: %d\n", min_element);
		printf_s("Line with min element: %d\n", line_index_min);
	};
	break;
	// {1, 2, 3}
	// {4, 5, 6}
	// {7, 8, 9}
	// Out:
	// 1 4 7 8 5 2 3 6 9
	case 3:
	{
		for (int j = 0; j < column_number; j++)
		{
			for (int i = 0; i < lines_number; i++)
			{
				if ((j+1) % 2 == 0)
				{
					printf_s("%d\t", matrix[lines_number - i - 1][j]);
				}
				else
				{
					printf_s("%d\t", matrix[i][j]);
				}
			}
		}
		printf_s("\n");
	}
	}
	return 0;
}