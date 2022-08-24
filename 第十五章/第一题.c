#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int sum=0;
	int i = 0;
	char ch;
	char num[8] = { 0 };
	while ((ch = getchar()) != '\n')
	{
		num[i] = ch-'0';
		i++;
	}
	for (int i = 0; i < 8; i++)
	{
		sum += num[i] ;
		if (i)
		sum *= 2;
	}
	printf("%d", sum);
	return 0;
}