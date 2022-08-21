#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
int main(int argc,char* argv[])
{
	long coordinate;
	char filename[40];
	FILE* fp;
	char buf[256] = { 0 };
	
	printf("Please enter a file name:\n");
	scanf("%s", filename);
	
	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("open to failed");
		exit(EXIT_FAILURE);
	}

	printf("Please enter a file coordinate:");
	while (scanf("%ld", &coordinate)==1&& (coordinate >= 0))
	{
		fseek(fp, coordinate, SEEK_SET);
		if(fgets(buf, 256, fp)==NULL)
			printf("FAILED");
		printf("%s",buf);
		printf("enter -1 or q to quit:");
	}

	return 0;
}