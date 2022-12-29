#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main(void)
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	//1
	int array[100][100];
	int column, rows, stolb, maxValue = -1000000;
	printf("������� ������������ ����� ���������� �������: ");
	scanf("%d", &rows);
	printf("������� ���������� �������� ���������� �������: ");
	scanf("%d", &column);

	for (int i = 0; i < rows; i++)
	{
		for (int k = 0; k < column; k++)
		{
			array[i][k] = i + k;
			printf(" %2d ", array[i][k]);
		}
		puts("\n");
	}

	printf("����� ������� ������� ������� ����� %d\n", array[0][0]);
	printf("\n������� ������ ��� ������ ������������ ��������: ");
	scanf("%d", &stolb);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (maxValue < array[i][stolb - 1])
			{
				maxValue = array[i][stolb - 1];
			}
		}
	}

	printf("\n������������ �������� %d ������ ������� ����� %d\n\n", stolb, maxValue);

	int matrix[7][7];
	int transMatrix[7][7];
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			matrix[i][j] = -10 + rand() % (10 - -10);
			printf(" %2d ", matrix[i][j]);
		}
		puts("\n");
	}

	puts("\n\n\n");
	int counter = 0;
	for (int i = 0; i < 7; i++) {
		for (int j = 1; j < 7; j++) {
			transMatrix[i][j] = matrix[j][counter];
			printf(" %2d ", transMatrix[i][j]);
		}
		counter++;
		puts("\n");
	}

	int counterMean = 0;
	double mean = 0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (j == 3)
			{
				if (transMatrix[i][j] % 2 == 0)
				{
					counterMean++;
					mean += transMatrix[i][j];
				}
			}
		}
	}
	printf("������� �������������� ������ ��������� �������� ������� %lf", mean / counterMean);

	int counterPair = 0;
	for (int i = 1; i < 7; i++)
	{
		for (int j = 1; j < 7; j++)
		{
			if (transMatrix[i][j] == transMatrix[i - 1][j])
			{
				counterPair++;
			}
			if (transMatrix[i][j] == transMatrix[i][j - 1])
			{
				counterPair++;
			}
		}
	}
	printf("\n%d ��� ����� �������", counterPair);

	int maxElem = -1000000;
	int coordsMaxElemX, coordsMaxElemY;

	for (int i = 0; i < 7; i++) 
	{
		for (int j = 0; j < 7; j++) 
		{
			if (maxElem <= transMatrix[i][j]) 
			{
				maxElem = transMatrix[i][j];
				coordsMaxElemX = i;
				coordsMaxElemY = j;
			}

		}
	}
	printf("\n������������ ������� - %d. ���������� � ����� � ������������ (%d;%d)", maxElem, coordsMaxElemX, coordsMaxElemY);

	int house[4][12];
	for (int i = 0; i < 4; i++) 
	{
		printf("\n�������� %d", i + 1);
		for (int j = 0; j < 12; j++) 
		{
			house[i][j] = 0 + rand() % (50 - 0);
			printf("\n		���� %d - %2d ", j + 1, house[i][j]);

		}
	}

	int floor, flat, minpeople = 100000;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			if (minpeople >= house[i][j])
			{
				minpeople = house[i][j];
				floor = j;
				flat = i;
			}
		}
	}

	printf("\n\n����������� ���������� ������� %d �� ����� %d �������� %d\n", minpeople, floor + 1, flat + 1);

	return 0;
}

