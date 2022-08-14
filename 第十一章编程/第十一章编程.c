#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
void one(void);//1
void in(char* ptr);//1
void three(void);//3
int num(char letter[]);//3
void five(void);//5
char* compare(char str1[], char ch, int a);//5
void eight(void);//8
char* string_in(char str1[], char str2[], int a, int b);//8
int main(void)
{
	//one();
	//three();
	//five();
	eight();
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
	} while ((!isblank(ch = getchar())) && !(ch == '\n'));
	while ((ch = getchar()) != EOF)
		continue;
	return i;
}

//5**************************************************************************************
void five(void)
{
	char ch;
	char* ptr;
	int i = 0;
	char str1[40];
	printf("ÊäÈë×Ö·û´®1");
	while ((str1[i] = getchar()) != '\n')
		i++;
	printf("ÊäÈë²éÕÒ×Ö·û");
	scanf("%c", &ch);
	ptr = compare(str1, ch, i);
	printf("%c %p", *ptr, ptr);
}

char* compare(char str1[], char ch, int a)
{
	for (int i = 0; i < a; i++)
	{
		if (str1[i] == ch)
			return str1 + i;
	}
	return 0;
}

//8**************************************************************************************
void eight(void)
{
	char ch;
	char* ptr;
	int i = 4; int n = 2;
	char str1[40];
	char str2[40];

	printf("ÊäÈë×Ö·û´®1");
	while ((str1[i] = getchar()) != '\n')
		i++;
	/*while ((ch = getchar()) != '\n')
		continue;*/
	printf("ÊäÈë×Ö·û´®2");
	while ((str2[i] = getchar()) != '\n')
		n++;
	ptr = string_in(str1, str2, i, n);
	printf("%c %p", *ptr, ptr);
}

char* string_in(char str1[], char str2[],int a, int b)
{
	_Bool num = 0;
	for (int i = 0; i < b; i++) 
	{
		for (int n = 0; n < a; n++)
			if (str1[n] == str2[i])num = 1;
		if (num==0)
			return 0;
		num = 0;
	}
	for (int i = 0; i < a; i++)
		if (str1[i] == str2[0])
			return str1 + i + 1;
}