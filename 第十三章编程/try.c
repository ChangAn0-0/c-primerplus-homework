#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
	char* source;
	char filename[40] = { 0 };
	FILE* fp;
	size_t file_size, read_size;

	printf("input filename:");
	scanf("%s", filename);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "open failed:%s", filename);
		exit(EXIT_FAILURE);
	}

	fseek(fp, 0L, SEEK_END);
	file_size = ftell(fp);
	rewind(fp);

	source = (char*)malloc(sizeof(char) * file_size);
	read_size = fread(source, 1, file_size, fp);
	fclose(fp);

	printf("%zu ", read_size);
	printf("%zu ", file_size);

	return 0;
}