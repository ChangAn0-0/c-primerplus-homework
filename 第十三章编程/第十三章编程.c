#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* s_gets(char* st, int n);//1
void one(void);//1
int main(int argc,char* argv[])
{
	one();
	return 0;
}

void one(void)
{
	char ch;
	FILE* fp;
	char name[40];
	unsigned long count = 0;
	printf("请输入打开文件名称");
	scanf("%s", name);
	//s_gets(name, 40);
	if ((fp = fopen(name, "r")) == NULL)
	{
		printf("%s文件打开失败", name);
		exit(EXIT_FAILURE);
	}
	while((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	fclose(fp);
	printf("%s有%lu个字符", name, count);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;
	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '/n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}