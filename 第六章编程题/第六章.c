#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//未写的题目可参照其他题解法，较为简单
void one(void);//第一题
void three(void);//第三题
void four(void);//第四题
void five(void);//第五题
void twelve(void);//第十二题
void fourteen(void);//第十四题
void fiveteen(void);//15
void sixteen(void);//16
void seventeen(void);//17
void eighteen(void);//18
int main(void)
{
	//one();
	//three();
	//four();
	//five();
	//twelve();
	//fourteen();
	//fiveteen();
	//sixteen();
	//seventeen();
	eighteen();
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

//第十二题*************************************
void twelve(void)
{
	int a;
	double sum=0;
	printf("输入次数\n");
	scanf("%d", &a);
	while (a > 0)
	{
		for (int i = 1; i <= a; i++)
			sum += 1 / (double)i;
		printf("%lf\n",sum);
		sum = 0;
		for (int n = 1; n <= a; n++)
		{
			if (n % 2)//判断为奇数项：n%2=1，执行。
				sum += 1 / (double)n;
			else//判断为偶数项
				sum -= 1 / (double)n;
		}
		printf("%lf\n", sum);
		sum = 0;
		printf("输入次数\n");
		scanf("%d", &a);
	}
	printf("程序结束\n");
}

//第十四题*****************************************
void fourteen(void)
{
	double sum = 0;
	double num1[8] = { 0 };
	double num2[8] = { 0 };
	printf("请依次输入8个数\n");
	for (int i = 0; i < 8; i++)
		scanf("%lf", &num1[i]);
	for (int i = 0; i < 8; i++)
		printf("%lf ", num1[i]);
	putchar('\n');
	for (int i = 0; i < 8; i++)
	{
		sum += num1[i];
		num2[i] = sum;
		printf("%lf ", num2[i]);
	}
}

//第十五题*************************************
void fiveteen(void)
{
	char ch[256] = { 0 };
	int i = 0;
	printf("请输入一行内容\n");
	while ((ch[i++]=getchar())!= '\n')
	i = strlen(ch);
	for (i; i - 1 >= 0; i--)
		printf("%c", ch[i - 1]);
}

//16****************************************
void sixteen(void)
{
	double num1, num2;
	int i = 0;
	num1 = num2 = 100;
	while (!(num2 > num1))
	{
		num1 += 10;
		num2 *= 1.05;
	    i++;
	}
	printf("%d年,%lf,%lf", i, num1, num2);
}

//17************************************************
void seventeen(void)
{
	double sum = 100;
	int i = 0;
	do {
		sum *= 1.08;
		sum -= 10;
		i++;
		printf("%lf \n", sum);
	} while (sum > 0);
	printf("%d", i);
}

//18*************************************
void eighteen(void)
{
	int friends = 5;
	int i = 1;
	do {
		friends = friends - i;
		friends *= 2;
		i++;
	} while (friends <= 150);
	printf("%d %d", i,friends);
}