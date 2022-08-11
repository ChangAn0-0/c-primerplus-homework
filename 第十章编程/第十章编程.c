#include <stdio.h>
void three(void);//3
int max(int num[], int n);//3
int main(void)
{
	three();
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