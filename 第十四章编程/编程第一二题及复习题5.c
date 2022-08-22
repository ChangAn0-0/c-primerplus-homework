#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SumDays(const struct month Year[], int n);
char* s_gets(char MonthName[], int n);


struct month {
	char *month_name;
	int month_days;
	int month_num;
};

int main(void)
{
	int n;
	char MonthName[20];
	struct month Year[12];
	char *name[] = {"Jan","Feb","Mar","Apr","May","JUne","JUl","Aug","Sep","Oct","Nov","Dec"};
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int arr[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };

	for (int i = 0; i < 12; i++)
	{
		//Year[i].month_name = (char*)malloc(5);
		//strcpy(Year[i].month_name,name[i]);
		Year[i].month_name = name[i];
		Year[i].month_days = days[i];
		Year[i].month_num = arr[i];
	}

	puts(Year[0].month_name);
	puts(Year[11].month_name);

	//printf("enter a month:");
	//scanf_s("%d", &n);
	//printf("%d",SumDays(Year, n));

	//s_gets(MonthName,20);


	return 0;
}

int SumDays(const struct month Year[],int n)
{
	int sum = 0;
	for (int i = 0; i < n - 1; i++)
		sum += Year[i].month_days;
	return sum;
}

char* s_gets(char MonthName[], int n)
{
	char* find, * str;
	str = fgets(MonthName, n, stdin);
	if (str)
	{
		if (find = strchr(MonthName, '\n'))
		{
			if (find)
				*find = '\0';
			else
				while (getchar() != '\n')
					continue;
		}
	}
	return str;
}