#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE 32

int bstoi(char* st);
char* itobs(int n, char* num);

int main(int argc, char* argv[])
{
	printf("%d\n", 7 | 16);
	char num[SIZE+1] = { 0 };
	int  result = 0;
	result = (~bstoi(argv[1]));
	itobs(result, num);
	printf("~%s is %s\n", argv[1], num);

	printf("%d", bstoi(argv[2]));

    result = (~bstoi(argv[2]));
	itobs(result, num);
	printf("~%s is %s\n", argv[2], num);

    result = (bstoi(argv[2])&bstoi(argv[1]));
	itobs(result, num);
	printf("%s&%s is %s\n", argv[1],argv[2], num);

	result = (bstoi(argv[2]) ^ bstoi(argv[1]));
	itobs(result, num);
	printf("%s^%s is %s\n", argv[1], argv[2], num);

	result = (bstoi(argv[2]) | bstoi(argv[1]));
	itobs(result, num);
	printf("%s|%s is %s\n", argv[1], argv[2], num);
}

int bstoi(char* st)
{
	int sum = 0;
	while (*st != '\0') {
		sum *= 2;
		if (*st != '0' && *st != '1')
		{
			puts("failed");
			exit(1);
		}
		sum = *st++-'0';
	}
	return sum;
}

char* itobs(int n,char*num) 
{
	int i;
	const static int size = CHAR_BIT * sizeof(int);
	for ( i = size - 1; i >= 0; i--, n >>= 1)
		num[i] = (01 & n) + '0';
	num[size] = '\0';
	return num;
}