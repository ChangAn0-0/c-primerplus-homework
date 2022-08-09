#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void two(void);//2
void chline(char ch, int i, int j);//2
void four(void);//4
double average(double i, double j);//4
void six(void);//6
void compare(double* ptr1, double* ptr2, double* ptr3);//6
void eleven(void);
int main(void)
{
	//two();
	//four();
	//six();
	eleven();
	return 0;
}


//2****************************************************************************************
void two(void)
{
	char ch;
	int i, j;
	printf("输入打印字符");
	scanf("%c", &ch);
	printf("输入打印行数");
	scanf("%d", &i);
	printf("输入打印列数");
	scanf("%d", &j);
	chline(ch, i, j);
}

void chline(char ch, int i, int j)
{
	for (int a=0; a < i; a++)
	{
		for ( int b=0; b < j; b++)
			putchar(ch);
		putchar('\n');
	}
}

//4*********************************************************************************************
void four(void)
{
	double i, j;
	printf("输入1\n");
	scanf("%lf", &i);
	printf("输入2\n");
	scanf("%lf", &j);
	printf("%lf",average(i,j));
}

double average(double i, double j)
{
	double a = 1 / i;
	double b = 1 / j;
	return 1 / ((a + b) / 2);
}

//6***********************************************************************************************
void six(void)
{
	double i, j, k;
	double* ptr1, * ptr2, * ptr3;
	ptr1 = &i; ptr2 = &j; ptr3 = &k;
	printf("输入1\n"); scanf("%lf", &i);
	printf("输入2\n"); scanf("%lf", &j);
	printf("输入3\n"); scanf("%lf", &k);
	compare(ptr1, ptr2, ptr3);
	printf("%lf %lf %lf",i,j,k);
	return;
}

void compare(double* ptr1, double *ptr2, double *ptr3)
{
	double num[3] = { *ptr1 ,*ptr2 ,*ptr3 };
	for (int i = 0; i < 2; i++)
		for (int j = i + 1; j < 3; j++)
			if(num[i]>num[j])
			{
				double a = num[j];
				num[j] = num[i];
				num[i] = a;
		    }
	*ptr1 = num[0]; *ptr2 = num[1]; *ptr3 = num[2];
}

//11*********************************************************************************************
void eleven(void)
{
	int n, num1, num2, num3;
	num1 = num2 = num3 = 1;
	printf("输入\n"); scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (i >= 3)
		{
			num3 = num1 + num2;
			num1 = num2;
			num2 = num3;
			
		}
			printf("%d ", num3);
	}
}