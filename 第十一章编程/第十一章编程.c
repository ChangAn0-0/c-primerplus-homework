#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
void one(void);//1
void in(char* ptr);//1
void three(void);//3
int num(char letter[]);//3
void five(void);//5
char* compare(char str1[], char ch, int a);//5
void seven(void);//7
void eight(void);//8
char* string_in(char str1[], char str2[], int a, int b);//8
void ten(void);//10
int main(void)
{
	//one();
	//three();
	//five();
	//seven();
	//eight();
	ten();
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
	printf("�����ַ���1");
	while ((str1[i] = getchar()) != '\n')
		i++;
	printf("��������ַ�");
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

//7****************************************************************************
void seven(void)
{
	int n, i = 0;
	char source[80], dest[80]={0};
	printf("�����ַ���");
	fgets(source, 80, stdin);
	printf("���븴����");
	scanf("%d", &n);
	while ((*source) != '\0' && i < n)
	{
		*(dest + i) = *(source + i);
		i++;
	}
	if (i < n)
		*(dest + i) = '\0';
	puts(dest);
}

//8**************************************************************************************
void eight(void)
{
	char* ptr;
	int i = 0; int n = 0;
	char str1[40];
	char str2[40];

	printf("�����ַ���1");
	while ((str1[i] = getchar()) != '\n')
		i++;
	printf("�����ַ���2");
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
		{
			if (str1[n] == str2[i])
			{
				num = 1;
				break;
			}
			else
				num = 0;
		}
		if(num==0)
			return 0;
	}
	for (int i = 0; i < a; i++)
		if (str1[i] == str2[0])
			return str1 + i;
	return 0;
}

//10*************************************************************
void ten(void)
{
	int n=0, i = 0;
	char source[80], dest[80] = { 0 };
	printf("�����ַ���");
	fgets(source, 80, stdin);
	while (*(source+(i)) != '\0') {
		if (*(source + i) != ' ')
		{
			*(dest + n) = *(source + i);
			n++; i++;
		}
		else
			i++;
	}
	//*(dest + n) = '\0';
	puts(dest);
}
