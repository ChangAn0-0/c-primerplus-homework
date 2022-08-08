#include <stdio.h>
void one(void);//1
void two(void);//two
int main(void)
{
	//one();
	two();
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