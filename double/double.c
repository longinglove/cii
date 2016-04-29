/*************************************************************************
	> File Name: double.c
	> Author: duqinglong
	> Mail: du_303412@163.com 
	> Created Time: 2016年04月29日 星期五 16时57分08秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<errno.h>

int main(int argc, char *argv[])
{
	int i;
	for (i = 1; i < argc; i++)
	{
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL)
		{
			fprintf(stderr, "%s: cant open '%s' (%s)\n", argv[0], argv[i], strerror(errno));
			return EXIT_FAILURE;
		}
		else
		{
			doubleword(argv[i], fp);
			fclose(fp);
		}
	}
	if (argc == 1)
		doubleword(NULL, stdin);
	return EXIT_SUCCESS;
}

int getword()
