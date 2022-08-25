#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
	char title[30];
	char rating;
	FILM* next;
}FILM;

int main(void) 
{
	FILM* head = NULL;
	FILM* seek, * input, * prve;
	char ch;

	printf("do you want to creat new film?(y/n)");
	scanf("%c", &ch);
	
	while (ch == 'y') {
		input = (FILM*)(malloc(sizeof(FILM)));
		if (head == NULL)
			head = input;
		else
			prve->next = input;
		input->next = NULL;

		printf("enter film title");

		printf("enter film rating");

		printf("do you want to creat new film?(y/n)");
		scanf("%c", &ch);

		prve = input;
	}


 }