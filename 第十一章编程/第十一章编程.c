#include <stdio.h>
void one(void);//1
void in(char* ptr);//1
int main(void)
{
	one();
	return 0;
}

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