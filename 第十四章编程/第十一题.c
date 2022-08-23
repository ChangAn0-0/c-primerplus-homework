#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LEN 10

void transform(double src[], double tar[], int n, double (*ptr)(double));

int main(void)
{
	double source[LEN], target[LEN];
	for (int i = 0; i < LEN; i++)
	{
		source[i] = i;
	}

	printf("the source data is\n");
	for (int i = 0; i < LEN; i++)
	{
		printf("%5g",source[i]);
	}
	putchar('\n');

	transform(source, target, LEN, sin);

	printf("the target data is\n");
	for (int i = 0; i < LEN; i++)
	{
		printf("%-6.3g ", target[i]);
	}
	putchar('\n');

	transform(source, target, LEN, cos);

	printf("the target data is\n");
	for (int i = 0; i < LEN; i++)
	{
		printf("%-6.3g ", target[i]);
	}
	putchar('\n');

	return 0;
}

void transform(double src[], double tar[], int n, double (*ptr)(double))
{
	for (int i = 0; i < LEN; ++i)
	{
		tar[i] = ptr(src[i]);
	}
}