#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void optimization(int picture[][31]);

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

	//存入数组
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 31; j++)
		{
			if (j == 30)
				picture[i][j] = '\0';
			else
				fscanf(fp, "%d", &picture[i][j]);
		}
	
	//展示数组
	printf("Original Image:\n");
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
			printf("%c", symbol[picture[i][j]]);
		putchar('\n');
	}

	//调用函数
	optimization(picture);
	return 0;
}

void optimization(int picture[][31])
{
	_Bool mark = 1;
	
	//优化
	for (int i=0; i < 20; i++)
	{
		for (int n=0; n < 30; n++) 
		{
			int sum = 0; int around = 0; mark = 1;
			if (i > 0)
			{
				if (abs(picture[i][n] - picture[i - 1][n]) <= 1)
					mark = 0;
				sum += picture[i - 1][n]; around++;
			}
			if (i < 19)
			{
				if (abs(picture[i][n] - picture[i + 1][n]) <= 1)
					mark = 0;
				sum += picture[i + 1][n]; around++;
			}
			if (n > 0)
			{
				if (abs(picture[i][n] - picture[i ][n-1]) <= 1)
					mark = 0;
				sum += picture[i][n - 1]; around++;
			}
			if (n < 29)
			{
				if (abs(picture[i][n] - picture[i][n + 1]) <= 1)
					mark = 0;
				sum += picture[i][n + 1]; around++;
			}
			if (mark == 1)
				picture[i][n] = sum / around;
		}
	}

	//展示数组
	printf("\nOptimized Image:\n");
	char symbol[10] = { ' ','.','\'',':','~','*','=','@','%','#' };
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
			printf("%c", symbol[picture[i][j]]);
		putchar('\n');
	}
}