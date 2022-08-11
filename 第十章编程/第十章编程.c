#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void three(void);//3
int max(int num[], int n);//3
void ten(void);//10
void sum(int a[], int b[], int c[]);//10
void thirteen(void);
void in(double(*ptr)[5]);
double averge(double(*ptr)[5]);
double averge_sum(double num[3][5]);
double max_num(double num[3][5]);
int main(void)
{
	//three();
	//ten();
	thirteen();
	return 0;
}

void two(void)
{
	double source[5] = { 1.1,2.2,3.3,4.4,5.5 };
	double copy1[5];
	double copy2[5];
	//double copy3[5];

	double* ptr1 = source;
	double* ptr2 = copy2;

	for (int i = 0; i < 5; i++)
		copy1[i] = source[i];
	for (int i = 0; i < 5; i++)
		*(ptr2 + i) = *(ptr1 + i);
}

//3************************************************************
void three(void)
{
	int num[5] = { 1,3,5,1,9 };
	printf("%d", max(num,5));
}

int max(int num[],int n)
{
	for (int i = 1; i < n; i++)
		num[0] = ((num[0] > num[i]) ? num[0] : num[i]);
	return num[0];
}

//10*************************************************************
void ten(void)
{
	int num_one[5] = { 1,2,3,4,5 };
	int num_two[5] = { 1,2,3,4,5 };
	int num_three[5] = { 0 };
	sum(num_one, num_two, num_three);
	for (int i = 0; i < 5; i++)
		printf("%d ", num_three[i]);
}

void sum(int a[], int b[], int c[])
{
	for (int i = 0; i < 5; i++)
		c[i] = a[i] + b[i];
}

//13***********************************************************
void thirteen(void)
{
	double num[3][5];
	double(*ptr)[5] = num;
	for (int i = 0; i < 3; i++)
	{
		in(ptr + i);
		double a=averge(ptr + i);
		printf("第%d组的平均数为%lf\n", i+1, a);
	}
	printf("平均数为%lf", averge_sum(num));
	printf("最大数%lf", max_num(num));
}

void in(double (*ptr)[5])
{
	printf("请输入5个数\n");
	for (int i = 0; i < 5; i++)
		scanf("%lf", (*ptr + i));
}

double averge(double(*ptr)[5])
{
	double averge=0;
	for (int i = 0; i < 5; i++) {
		averge += *(*ptr + i);
	}
	return averge/5;
}

double averge_sum(double num[3][5])
{
	double sum=0;
	for (int i = 0; i < 3; i++)
		for (int n = 0; n < 5; n++)
			sum += num[i][n];
	return sum / 15;
}

double max_num(double num[3][5])
{
	double max=num[0][0];
	for (int i = 0; i < 3; i++)
		for (int n = 0; n < 5; n++)
			max = ((max > num[i][n]) ? max : num[i][n]);
	return max;
}
