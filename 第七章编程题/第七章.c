#include <stdio.h>
void one(void);//1
void two1(void);/*第二题可以看到我写了两个函数two和two1，第一个是一开始写的，但是运行的时候出现了一个问题
				即按下enter键时，便开始输出打印，这无法是我在按下enter键后继续输入其他字符，这和我预想的不一样，
				但是第一个程序却没有遇到这个问题，我猜是第一个printf写在循环外的原因，enter键除了输入字符'\n'
				应该还有其他作用，比如刷新这个循环？所以printf写在循环内导致了问题的发生？所以我写了two1这个
				程序，我把printf和while的循环分开，先储存再输出，这次果然没有收到影响。*/
void four(void);//4
void six(void);//6,此为错误解法。
void six1(void);//6
int main()
{
	//one();
	//two1();
	//four();
	six1();
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
			putchar('!');//while循环内的输出存在与2同样的问题。
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
	char ch; int i = 0;
	while ((ch = getchar()) != '#')
	{
		if (ch == 'e')
			if (getchar() == 'i')//此处有误，当输入为eei时，中间的e被此处的getchar获取，                
				i++;             //之后的while循环中的getchar获取i，导致程序输出为0。
	}                            //所以在while循环中应该避免用getchar。
	printf("%d", i);
}

void six1(void)//此为书本答案的解法，我的本意是如同two1一样，先设置数组读入输入，然后通过
{              //arr[i]=='e'&&arr[i+1]=='i'是否为真来判断，不过我觉得答案的解法更好。
	char ch; int j,i;
	j = i = 0;
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case'e':j = 1; break;
		case'i':if (j) {
			i++; j = 0;
		}break;
		default:j = 0;
		}
	}
	printf("%d", i);
}

//7****************************************************
void seven(void)
{

}