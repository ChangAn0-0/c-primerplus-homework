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
	printf("�����ӡ�ַ�");
	scanf("%c", &ch);
	printf("�����ӡ����");
	scanf("%d", &i);
	printf("�����ӡ����");
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