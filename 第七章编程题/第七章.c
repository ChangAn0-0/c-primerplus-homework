#include <stdio.h>
void one(void);//1
int main()
{
	one();
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
	printf("�ո�%d,���У�%d,������%d", i, j, k);
}