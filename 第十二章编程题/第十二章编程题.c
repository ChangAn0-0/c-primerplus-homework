#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void five(void);//5
void four(void);//4
int frequency(void);//4
void six(void);//6
int main(void)
{
	//four();
	//five();
	six();
	return 0;
}

//4******************************************************************
void four(void)
{
	int num;
	for (int i = 0; i < 9; i++)
		num =frequency();
	printf("%d", num);
}

int frequency(void)
{
	static int fre = 0;
	fre++;
	return fre;
}

//5******************************************************************
void five(void)
{
	int num[100];
	srand(time(0));
	for (int i = 0; i < 100; i++)
	{
		num[i] = rand() % 10 + 1;
	}
	
	for (int i = 0; i < 100; i++)
		for (int j = i+1; j < 100; j++)
		{
			int a = 0;
			if (num[i] <= num[j])
			{
				a = num[i];
				num[i] = num[j];
				num[j] = a;
			}
		}

	for (int i = 0; i < 100; i++)
		printf("%d ", num[i]);

}

//6***************************************************************************
void six(void)
{
	int num[1000];
	srand(time(0));
	int frequency = 0;
	for (int i = 0; i < 1000; i++)
	{
		num[i] = rand() % 10 + 1;
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (i == num[j])
				frequency++;
		}
		printf(" % d: % d\n", i, frequency);
		frequency = 0;
	}
}