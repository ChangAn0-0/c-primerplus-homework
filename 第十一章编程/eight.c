#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define NUM 40 

char* string_in(char str1[], char str2[], int count1, int count2);

int main(void)
{
	char ch;
	char* ptr;
	char str1[NUM] = {0};
	char str2[NUM] = {0};
	int count1 = 0, count2 = 0;
	
	printf("enter the frist set of strings:");
	while ((ch = getchar()) != '\n')
	{
		str1[count1] = ch;
		count1++;
	}

	printf("enter the sceond set of strings:");
	while ((ch = getchar()) != '\n')
	{
		str2[count2] = ch;
		count2++;
	}

	ptr = string_in(str1, str2, count1, count2);
	putchar(*ptr);
	//printf("%d", count1);
	//printf("%d", count2);
	//puts(str1);
	//puts(str2);

}

char* string_in(char str1[], char str2[], int count1, int count2)
{
	_Bool mark = 0;
	int point = 0;
	for (int i = 0; i < count1; i++)
	{
		int n = 0;
		if (str1[i] = str2[n])
		{
			point = i;
			for (n; n < count2;)
			{
				if(point>count1)
				{
					mark = 0;
					return 0;
				}
				n++; point++;
				if (str1[point] = str2[n])
				{
					mark = 1;
					continue;
				}
				else
					break;
			}
			if (mark == 1)
				return (str1+point - count2);
		}
	}
	return 0;
}
