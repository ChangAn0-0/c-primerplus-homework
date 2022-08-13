#include <stdio.h>
#include <ctype.h>
#include <string.h>
int myatoi(char num[], int i);
//13***************************************************
//int main(int argc, char *argv[])
//{
//	int n;
//	n = argc;
//	for (int i = n; i > 1; i--)
//		printf("%s ",argv[i-1]);
//	return 0;
//}

//15*****************************************************
int main(void)
{
	char ch; int i = 0;
	char num[10];
	printf("ÇëÊäÈëÊı×Ö");
	while ((ch = getchar()) != '\n')
		num[i++] = ch;
	printf("%d", myatoi(num, i));
	return 0;
}

int myatoi(char num[],int i)
{
	int sum=0;
	for (int n = 0; n < i; n++)
	{
		if (!(isdigit(num[n])))
			return 0;
		else {
			sum += (num[n]-'0');
			sum *= 10;
		}
	}
	return sum/10;
}
