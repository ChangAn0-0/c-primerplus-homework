#include <stdio.h>
int main(void)
{
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