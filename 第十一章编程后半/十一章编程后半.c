#include <stdio.h>
//13***************************************************
int main(int argc, char *argv[])
{
	int n;
	n = argc;
	for (int i = n; i > 1; i--)
		printf("%s ",argv[i-1]);
	return 0;
}

