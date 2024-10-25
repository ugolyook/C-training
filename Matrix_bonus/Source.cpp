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
	printf_s("Choise what you want to do\n1-transpose matrix\n2-change line with max element with line that consist min element\n");
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
		for (int i = 0; i < lines_number; i++)
		{
			for (int j = 0; j < column_number; j++)
			{
				if (matrix[i][j] > max_element)
				{
					max_element = matrix[i][j];
				}

				if (matrix[i][j] < min_element)
				{
					min_element = matrix[i][j];
				}
			}
		}
		printf_s("Max element: %d\n", max_element);
		printf_s("Line with max element: %d\n", i);
		printf_s("Min element: %d\n", min_element);
		printf_s("Line with min element: %d\n", i);
	};
	break;
	}
	return 0;
}