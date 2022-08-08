#include <stdio.h>
void one(void);//1
int main(void)
{
	one();
	return 0;
}

void one(void)
{
	int i = 0;
	while (getchar() != EOF)
		i++;
	printf("%d", i);
}