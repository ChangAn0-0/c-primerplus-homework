#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int number;
	_Bool reserve;
	char fname[15];
	char lname[15];
}INFORMATION;

void show_menu(void);
void show_NumEmptySeat(INFORMATION* ptr);
void show_NumEmptySeatList(INFORMATION* ptr);
void show_reserved(INFORMATION* ptr);
void book_seat(INFORMATION* ptr);
void book_delete(INFORMATION* ptr);
void choose(INFORMATION* ptr);


int main(void)
{
	INFORMATION* ptr;
	INFORMATION seat[12] = { 0 };
	ptr = seat;

	for (int i = 0; i < 12; i++)
		(ptr + i)->number = i;
	//show_menu();
	/*while (1)
	{
		char ch;
		scanf("%c", &ch);
		switch (ch)
		{
		case 'a':show_NumEmptySeat(ptr); break;
		case 'b':show_NumEmptySeatList(ptr); break;
		case 'c':show_reserved(ptr); break;
		case 'd':book_seat(ptr); break;
		case 'e':book_delete(ptr); break;
		case 'f':exit(EXIT_SUCCESS);
		default:break;
		}
		show_menu();
	}*/
	choose(ptr);

	return 0;
}

void show_menu(void)
{
	printf("To choose a function,enter its letter label:\n");
	printf("a) Show number of empty seats\n");
	printf("b) Show list of empty seats\n");
	printf("c) Show alphaetical list of seats\n");
	printf("d) Assign a customer to a seat assignment\n");
	printf("e) Delete a seat assignment\n");
	printf("f) Quit\n");
}

void show_NumEmptySeat(INFORMATION* ptr)
{
	int num = 0;
	for (int i = 0; i < 12; i++)
		if ((ptr + i)->reserve == 0)
			num++;
	printf("empty seats number:%d\n", num);
}

void show_NumEmptySeatList(INFORMATION* ptr)
{
	printf("empty seats:\n");

	for (int i = 0; i < 12; i++)
		if ((ptr + i)->reserve == 0)
			printf("%d ", ((ptr + i)->number)+1);
	putchar('\n');
}

void show_reserved(INFORMATION* ptr)
{
	INFORMATION* point[12];
	for (int i = 0; i < 12; i++)
		point[i] = (ptr + i);
	INFORMATION* temp;
	int top, seek;
	for(top=0;top<12-1;top++)
		for (seek = top + 1; seek < 12;seek++)
		{
			if (strcmp(point[top]->fname, point[seek]->fname) > 0) {
				temp = point[top];
				point[top] = point[seek];
				point[seek] = temp;
			}
		}

	puts("list:");
	for (int i = 0; i < 12; i++)
	{
		if (point[i]->reserve == 1) {
			printf("seat no:%d book by %10s.%-10s\n", point[i]->number+1, point[i]->fname,
				point[i]->lname);
		}
		else
			printf("seat %d is empty\n", point[i]->number+1);
	}
}

void book_seat(INFORMATION* ptr)
{
	char fname[15];
	char lname[15];
	int num;
	puts("enter a seat number:");
new: scanf("%d", &num);
	if ((ptr + num - 1)->reserve == 1)
	{
		puts("Seat is already reserved!");
		puts("enter new seat number:");
		goto new;
	}
	puts("enter first name,last name");
	scanf("%s %s", fname, lname);
	(ptr + num - 1)->reserve = 1;
	strcpy((ptr + num - 1)->fname, fname);
	strcpy((ptr + num - 1)->lname, lname);
	puts("booked!");
}

void book_delete(INFORMATION* ptr)
{
	int num;

	show_reserved(ptr);

	puts("enter a seat number to delete");
	scanf("%d", &num);
	(ptr + num - 1)->reserve = 0;
	puts("Ok");
}

void choose(INFORMATION* ptr)
{
	while (1) {
		show_menu();
		char ch;
		scanf("%c", &ch);
		switch (ch)
		{
		case 'a':show_NumEmptySeat(ptr); break;
		case 'b':show_NumEmptySeatList(ptr); break;
		case 'c':show_reserved(ptr); break;
		case 'd':book_seat(ptr); break;
		case 'e':book_delete(ptr); break;
		case 'f':return;
		default:break;
		}
		while (getchar() != '\n');
	}
}