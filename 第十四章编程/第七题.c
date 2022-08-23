#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 20

char* s_gets(char* st, int n)
{
	char* ptr1, * ptr2;
	ptr1 = fgets(st,n,stdin);
	if (ptr1) {
		if (ptr2 = strchar(st, '\n'))
			*ptr2 = '\0';
		else
			while (getchar() != '\n');
	}
	return ptr1;
}

typedef struct {
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int delete_falg;
}BOOK;

int main(void)
{
	BOOK library[MAXBKS];
	int count = 0;
	int index, filecount;
	FILE* pbooks;
	int size = sizeof(BOOK);
	char delete;

	if ((pbooks = fopen("book.dat", "r+b"))) {
		fputs(stderr, "open failed");
		exit(1);
	}
	rewind(pbooks);

	while (count < MAXBKS && fread(&library[count], size, 1, pbooks)==1)
	{
		if (count == 0) {
			puts("current contents of book.dat");
		}
		printf("%s by %s: $%.2f\n", library[count].title, library[count].author,
			library[count].value);
		count++;
	}

	filecount = count;

	if (count == MAXBKS)
	{
		puts("full");
		exit(2);
	}

	printf("Do you want to modefy library?(y/n):");
	scanf("%c", &delete);

	if (delete == 'y')
	{
		for (int i = 0; i < count; i++) {
			delete = 'n';
			printf("%s by %s: $%.2f\n", library[count].title, library[count].author,
				library[count].value);
			while (getchar() != '\n')
				continue;
			puts("do you want to delete this book?(Y/N)");
			scanf("%c", &delete);
			if (delete == 'Y')library[i].delete_falg = 1;
		}
	}

	while (getchar() != '\n') {
		continue;
	}

	puts("add new book");
	puts("press [enter] at the start of a line to stop");

}