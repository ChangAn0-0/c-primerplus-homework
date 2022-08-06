#include <stdio.h>
void one(void);//1
void two1(void);/*第二题可以看到我写了两个函数two和two1，第一个是一开始写的，但是运行的时候出现了一个问题
				即按下enter键时，便开始输出打印，这无法是我在按下enter键后继续输入其他字符，这和我预想的不一样，
				但是第一个程序却没有遇到这个问题，我猜是第一个printf写在循环外的原因，enter键除了输入字符'\n'
				应该还有其他作用，比如刷新这个循环？所以printf写在循环内导致了问题的发生？所以我写了two1这个
				程序，我把printf和while的循环分开，先储存再输出，这次果然没有收到影响。*/
void four(void);//4
int main()
{
	//one();
	two1();
	//four();
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
	char ch;
	int i = 0;
	while ((ch = getchar()) != '#')
	{
		printf("%3d ", ch);
		i++;
		if (!(i % 8))
			putchar('\n');
	}
}

void two1(void)
{
	char arr[10000] = { 0 };
	char ch;
	int i = 0;
	while ((ch = getchar()) != '#')
	{
		arr[i] = ch;
		i++;
	}
	int n = 0;
	for (n; n < i; n++)
	{
		if (!(n % 8))
			putchar('\n');
		printf("%3d ", arr[n]);
	}
}

//4***************************************************
void four(void)
{
	char ch;
	while ((ch= getchar()) != '#')
	{
		if (ch == '.')
			putchar('!');
		else if (ch == '!')
		{
			putchar('!');
			putchar('!');
		}
		else
			putchar(ch);
	}
}

//6**************************************************
void six(void)
{
	char ch;
	while ((ch = getchar()) != '#')
	{
	if(ch=='e')

	}
}