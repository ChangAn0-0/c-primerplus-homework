#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int number;
	char fname[15];
	char lname[15];
	int start;
	int hits;
	int numbases;
	int rbi;
	double avarage;
}Player_Information;


void read(Player_Information* ptr, FILE* fp);
void set_avarage(Player_Information* ptr);
void show(Player_Information* ptr);


int main(void)
{
	FILE* fp;
	Player_Information* ptr;
	Player_Information team[19] = { 0 };
	ptr = team;

	if ((fp = fopen("team.txt", "r")) == NULL)
	{
		printf("open failed");
		exit(EXIT_FAILURE);
	}

	read(ptr, fp);
	set_avarage(ptr);
	show(ptr);

	return 0;
}

void read(Player_Information* ptr, FILE* fp)
{
	int number;
	char fname[15];
	char lname[15];
	int start;
	int hits;
	int numbases;
	int rbi;
	int read_count;
	while (1)
	{
		read_count = fscanf(fp, "%d %s %s %d %d %d %d", &number, fname, lname, &start,
			&hits, &numbases, &rbi);
		if (read_count < 7)
			break;
		(ptr + number)->number = number;
		strcpy((ptr + number)->fname, fname);
		strcpy((ptr + number)->lname, lname);
		(ptr + number)->start += start;
		(ptr + number)->hits += hits;
		(ptr + number)->numbases += numbases;
		(ptr + number)->rbi += rbi;
	}
}

void set_avarage(Player_Information* ptr)
{
	for (int i = 0; i < 19; i++){
		(ptr + i)->avarage +=(double)((ptr + i)->hits)/ (ptr + i)->start;
	}
}

void show(Player_Information* ptr)
{
	for (int i = 0; i < 19; i++){
		printf("%2d %10s.%-10s %5d %5d %5d %5d %.2lf\n",
			(ptr + i)->number, (ptr + i)->fname, (ptr + i)->lname,
			(ptr + i)->start, (ptr + i)->hits, (ptr + i)->numbases,
			(ptr + i)->rbi, (ptr + i)->avarage);
	}
}

