#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char* s_gets(char* st, int n);//1
void one(void);//1
void two(char* file1, char* file2);//
void five_review(char* ch, char* file);//five_review
void three(void);//3
void twelve(void);//12
//void fourteen(char* symbol[31]);//14

int main(int argc,char* argv[])
{
	//one();
	//two(argv[1], argv[2]);
	//five_review(argv[1], argv[2]);
	//three();
	twelve();
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

//2****************************************************************************************
void two(char *file1,char* file2)
{
	size_t bytes;
	FILE* ptr1; FILE* ptr2;
	char temp[4096];
	if((ptr1 = fopen(file1, "rb"))==NULL)
	{
		fprintf(stderr, "无法打开文件%s", file1);
		exit(EXIT_FAILURE);
	}
	if(setvbuf(ptr1,NULL,_IOFBF,4096)!=0)
	{
		fputs("file1申请缓冲失败", stderr);
		exit(EXIT_FAILURE);
	}
	if (strcmp(file1, file2) == 0)
	{
		fputs("无法对相同文件进行操作",stderr);
	}
	if ((ptr2 = fopen(file2, "wb")) == NULL)
	{
		fprintf(stderr, "打开文件%s失败", file2);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(ptr2, NULL, _IOFBF, 4096)!=0)
	{
		fputs("file2申请缓冲失败", stderr);
		exit(EXIT_FAILURE);
	}
	while((bytes = fread(temp, sizeof(char), 4096, ptr1)) > 0)
		fwrite(temp, sizeof(char), bytes, ptr2);
	if(ferror(ptr1)!=0)
		fputs("file读取失败", stderr);
	if (ferror(ptr2) != 0)
		fputs("file输入失败", stderr);
	fclose(ptr1);
	fclose(ptr2);
}

//复习题5*************************************************************************************
void five_review(char *ch,char* file)
{
	char line[256];
	FILE* ptr1;
	if ((ptr1 = fopen(file, "r")) == NULL)
	{
		fprintf(stderr, "failed to open,\"%s\"", file);
		exit(EXIT_FAILURE);
	}
	
	while ((fgets(line, 256, ptr1)) != NULL)
	{
		if (strchr(line, *ch) != NULL)
			puts(line);
	}
}

//3*************************************************************************
void three(void)

{
	size_t bytes;
	FILE* ptr; 
	char name[40];
	char copy[256];
	printf("输入文件名");
	//s_gets(name, 40);
	//fgets(name, 40, stdin);
	scanf("%s", name);
	if ((ptr = fopen(name, "r+")) == NULL)
	{
		fprintf(stderr, "failed to open,%s", name);
		exit(EXIT_FAILURE);
	}
	setvbuf(ptr, NULL, _IOFBF, 256);
	while ((bytes = fread(copy,1, 256, ptr)) > 0)
	{
		char* s = copy;
		while (*s)
		{
			*s = toupper(*s);
			s++;
		}
		rewind(ptr);
		fwrite(copy, 1, bytes, ptr);
	}
	fclose(ptr);
}

//12************************************************************************************************
void twelve(void)
{
	char ch; int i = 0; int n = 0;
	char symbol[10] = { ' ','.','\'',':','~','*','=','@','%','#' };
	char picture[20][31]={0};
	//char**ptr = picture;
	FILE* fp;
	if ((fp = fopen("picture.txt", "r")) == NULL)
	{
		printf("打开文件失败");
		exit(EXIT_FAILURE);
	}
	printf("Original Image:\n");
	while ((ch = getc(fp)) != EOF)
	{
		if (ch == ' ')
			continue;
		else if (ch == '\n')
		{
			putchar('\n');
			picture[n][i] = '\0';
			i = 0; n = n + 1;
		}
		else
		{
			putchar(symbol[ch - '0']);
			picture[n][i] = symbol[ch - '0'];
			i++;
		}
	}
	int m = 0, k = 0;
	_Bool mark = 1;
	printf("\nOptimized Image:\n");
	for (m; m < 20; n++)
	{
		for (k; k < 30; i++)
		{
			int sum = 0, around = 0;
			if (k > 0)
			{
				if (abs(picture[m][k] - picture[m][k - 1]) <= 1)
				{
					mark = 0;
					sum += picture[m][k - 1];
					around++;
				}

			}
			if (m > 0)
			{
				if (abs(picture[m][k] - picture[m - 1][k]) <= 1)
				{
					mark = 0;
					sum += picture[m - 1][k];
					around++;
				}

			}
			if (k < 30)
			{
				if (abs(picture[m][k + 1] - picture[m][k]) <= 1)
				{
					mark = 0;
					sum += picture[m][k + 1];
					around++;
				}

			}
			if (m < 20)
			{
				if (abs(picture[m + 1][k] - picture[m][k]) <= 1)
				{
					mark = 0;
					sum += picture[m + 1][k];
					around++;
				}

			}
			if (mark == 1)
				picture[m][k] = sum / around;
		}
	}
	for (int n=0; n < 20; n++)
	{
		for (int i=0; i < 30; i++)
			putchar(picture[n][i]);
	}
	putchar('\n');
}

//14***********************************************************************************************
/*void fourteen(char symbol)
{
	int i = 0, n = 0;
	_Bool mark= 1;
	printf("\nOptimized Image:\n");
	for (n; n < 20; n++)
	{
		for (i; i < 30;i++) 
		{
			int sum = 0, around = 0;
			if (i > 0) 
			{
				if (abs(symbol[n][i] - symbol[n][i - 1]) <= 1)
				{
					mark = 0;
					sum += symbol[n][i - 1];
					around++;
				}

			}
			if (n > 0)
			{
				if (abs(symbol[n][i] - symbol[n-1][i]) <= 1)
				{
					mark = 0;
					sum += symbol[n-1][i];
					around++;
				}

			}
			if (i < 30)
			{
				if (abs(symbol[n][i+1] - symbol[n][i]) <= 1)
				{
					mark = 0;
					sum += symbol[n][i+1];
					around++;
				}

			}
			if (n < 20)
			{
				if (abs(symbol[n+1][i] - symbol[n][i]) <= 1)
				{
					mark = 0;
					sum += symbol[n+1][i];
					around++;
				}

			}
			if (mark == 1)
				symbol[n][i] = sum / around;
		}
	}
}*/

//*************************************************************************************************
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