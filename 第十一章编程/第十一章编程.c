#include <stdio.h>
#include <ctype.h>
void one(void);//1
void in(char* ptr);//1
void three(void);//3
int num(char letter[]);//3
int main(void)
{
	//one();
	three();
	return 0;
}

//1**********************************************************************************
void one(void)
{
	char ch[100] = { 0 };
	in(ch);
	for (int i = 0; i < 100; i++)
		putchar(ch[i]);
}

void in(char* ptr)
{
	int i = 0;
	while ((*(ptr + i) = getchar()) != EOF)
		i++;
}

//3**************************************************************************************
void three(void)
{
	int n = 0;
	char letter[20];
	n = num(letter);
	for (int i = 0; i < n; i++)
		printf("%c", letter[i]);
}

int num(char letter[])
{
	char ch; int i = 0;
	while (isblank(ch = getchar()))
		continue;
	do {
		letter[i]=ch;
		i++;
	} while (!isblank(ch = getchar())&&!(ch=='\n'));
	while ((ch = getchar()) != EOF)
		continue;
	return i;
}