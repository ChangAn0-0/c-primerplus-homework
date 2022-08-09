#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void two(void);//2
void chline(char ch, int i, int j);//2
int main(void)
{
	two();
	return 0;
}

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