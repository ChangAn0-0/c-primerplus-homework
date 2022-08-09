#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void one(void);//1
void two(void);//two
void eight(void);//8
float get_num(int n);
int main(void)
{
	//one();
	//two();
	eight();
	return 0;
}

void one(void)
{
	int i = 0;
	while (getchar() != EOF)
		i++;
	printf("%d", i);
}

void two(void)
{
	int i = 0;
	char ch;
	while ((ch=getchar()) != EOF)
	{
		if (i == 9)
		{
			putchar('\n');
			i = 0;
		}
		if (ch > ' ')
			printf(" %c--%3d ", ch, ch);
		else if(ch=='\n')
			printf(" \\n--%3d ", ch);
		else if (ch == '\t')
			printf(" \\t--%3d ", ch);
		else 
			printf("^%c--%3d ", ch+64, ch);
		i++;
	}
}

void eight(void)
{
	char ch;
	int a = 1, b = 2;
	//float num1, num2;
	double num;

start:printf("请选择计算方式\n");
	printf("a.add  s.subtract  m.multiply  d.divide\n");
	printf("q.quit\n");

	switch (ch = getchar())
	{		
	case'a': {
		num = (double)get_num(a) + get_num(b);
		printf("%f", num); goto start;
	}
	case's': {
		num = (double)get_num(a) - get_num(b);
		printf("%f", num); goto start;
	}
	case'm': {
		num = (double)get_num(a) * get_num(b);
		printf("%f", num); goto start;
	}
	case'd': {
		num = get_num(a) / get_num(b);
		printf("%f", num); goto start;
	}
	case'q':break;
	default:printf("未知指令"); goto start;
	}
}

float get_num(int n)
{
	float num;
get:printf("请输入值%d", n);
	if (scanf("%f", &num)==0)
		goto get;
	return num;
}