#include <stdio.h>
void one(void);//1
void two(void);//2
int main()
{
	one();
	//two();
	return 0;
}

//1***********************************************
void one(void)
{
	char ch; int i, j, k;
	i = j = k = 0;
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case' ':i++; break;
		case'\n':j++; break;
		default:k++;
		}
	}
	printf("空格：%d,换行：%d,其他：%d", i, j, k);
}

//2*********************************************
void two(void)
{
	char ch; int i = 0;
	while ((ch = getchar()) != '#')
	{
		if(ch=='\n')
			printf("%3d ", ch);
		printf("%3d ", ch);
		i++;
		if (!(i % 8))
			putchar('\n');
	}
}