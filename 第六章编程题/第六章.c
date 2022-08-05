#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void one(void);//第一题
               //第二题参照第三题
void three(void);//第三题
void four(void);//第四题
void five(void);//第五题
int main(void)
{
	//one();
	//three();
	//four();
	five();
	return 0;
}

//第一题****************************************************
void one(void)
{
	int i = 0 ;
	char arr[26] = { 0 };
	char ch = 'a';
	for ( i = 0; i < 26; i++)
	{
		arr[i] = 'a' + i;
	}
	i = 0;
	while (i < 26)
	{
		printf("%c ", arr[i]);
		i++;
	}
}

//第三题*********************************************
void three(void)
{
	char ch = 'F';
	int i,j;
	for (i = 1; i < 7; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%c", ch - j);
		}
		putchar('\n');
	}
}

//第四题****************************************
void four(void)
{
	char ch[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//假设系统不使用ASCII或其他以数字为顺序的代码
	int i, j, k=0;
	for (i = 1; i < 7; i++)
	{
		for (j = 0; j < i; j++)
		{
			printf("%c",ch[k++]);
		}
		putchar('\n');
	}
}

//第五题*******************************************
void five(void)
{
	char ch;
	printf("请输入大写字母");
	scanf("%c",&ch);
	int a = 0;
	int b = ch - 'A';

	for (a; ('A' + a) <= ch; a++,b--)
	{
		for (int i = 0; i <= b; i++)
			putchar(' ');
		for (int j = 0; j <=a ; j++)
			printf("%c", 'A' + j);
		for (int k = 1; k <= a; k++)
			printf("%c", ch - k);
		putchar('\n');
	}

}

//第十二题第二个序列****************************************
void twelve(void)
{
	int ch;
	printf("请输入次数");
	scanf("%c", &ch);

}