#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void show(int picture[][31]);

int main(void)
{
	char symbol[10] = { ' ','.','\'',':','~','*','=','@','%','#' };
	int picture[20][31] = { 0 };
	FILE* fp;
	if ((fp = fopen("file.txt", "r")) == NULL)
	{
		printf("打开文件失败");
		exit(EXIT_FAILURE);
	}
	printf("Original Image:\n");
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 31; j++)
		{
			if (j == 30)
				picture[i][j] = '\0';
			else
				fscanf(fp, "%d", &picture[i][j]);
		}
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
			printf("%c", symbol[picture[i][j]]);
		putchar('\n');
	}
	//show(picture);
	return 0;
}
void show(int picture[][31])
{
	int m = 0, k = 0;
	_Bool mark = 1;
	printf("\nOptimized Image:\n");
	for (m; m < 20; m++)
	{
		for (k; k < 30; k++)
		{
			int sum = 0, around = 0;
			if (k > 0)
			{
				if (abs(picture[m][k] - picture[m][k - 1]) <= 1)
				{
					mark = 0;
					sum += picture[m][k - 1];
					around++;
				}

			}
			if (m > 0)
			{
				if (abs(picture[m][k] - picture[m - 1][k]) <= 1)
				{
					mark = 0;
					sum += picture[m - 1][k];
					around++;
				}

			}
			if (k < 29)
			{
				if (abs(picture[m][k + 1] - picture[m][k]) <= 1)
				{
					mark = 0;
					sum += picture[m][k + 1];
					around++;
				}

			}
			if (m < 19)
			{
				if (abs(picture[m + 1][k] - picture[m][k]) <= 1)
				{
					mark = 0;
					sum += picture[m + 1][k];
					around++;
				}

			}
			if (mark == 1)
				picture[m][k] = sum / around;
		}
	}
}