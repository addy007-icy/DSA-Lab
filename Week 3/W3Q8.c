#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int length;

int main(int argc, char *argv[])
{	char line[500];
	FILE *fptr;

	if (argc <= 2)
	{
		printf("insufficient commands\n");
		return 0;
	}
	else if ( argc == 3  && strcmp(argv[2],"t") == 0)
	{	
		int count = 0;
		if ((fptr = fopen(argv[1], "r")) == NULL)
		{
			printf("Cant open file\n");
			return 0;
		}

		int i = 0;
		while (count < 10 && fgets(line, sizeof(line), fptr) )
		{
			printf(" %d %s", i + 1, line);
			count++;
			i++;
		}
	}
	else if (argc == 4  && strcmp(argv[3],"t") == 0)
	{
		int count = 0;
		if ((fptr = fopen(argv[2], "r")) == NULL)
		{
			printf("Cant open file\n");
			return 0;
		}
		else
		{	if (atoi(argv[1]) < 0)
			{	int i = 0;
				while ( count < (atoi(argv[1]) * -1))
				{
					fgets(line, sizeof(line), fptr);
					printf(" %d %s", i + 1, line);
					count++;
					i++;
				}
			}
			else
				printf("USAGE: ./a.out -numlines filename t/b\n");
			}
	}
	else if (argc == 3  && strcmp(argv[2],"b") == 0)
	{	
		if ((fptr = fopen(argv[1], "r")) == NULL)
		{
			printf("Cant open file\n");
			return 0;
		}
		int l = 0;
		while (fgets(line, sizeof(line), fptr) )
		{
			l++;
		}
		rewind(fptr);
		int start = l - 10  ;
		int c= 0;
		if (start < 0)
		{	while (fgets(line, sizeof(line), fptr) != NULL)
			{
				printf("%d %s", c+1, line);
				c++;
			}
		}
		else
		{	int i = 0;
			while (i < start)
			{
				fgets(line, sizeof(line), fptr);
				i++;
			}
			while (fgets(line, sizeof(line), fptr))
			{
				printf("%d %s", c+1, line);
				c++;
			}
		}
	}
	else if (argc == 4  && strcmp(argv[3],"b") == 0)
	{
		if ((fptr = fopen(argv[2], "r")) == NULL)
		{
			printf("Cant open file\n");
			return 0;
		}

		int l = 0;
		while (fgets(line, sizeof(line), fptr) )
		{
			l++;
		}
		rewind(fptr);
		int start = l - (atoi(argv[1]) * -1) ;
		int c=0;
		if (atoi(argv[1]) < 0)
		{	int i = 0;
			if (start < 0)
			{	while (fgets(line, sizeof(line), fptr))
				{
					printf("%d %s", c+1,line);
					c++;
				}
			}
			else
			{
				while (i < start)
				{
					fgets(line, sizeof(line), fptr);
					i++;
				}

				while (fgets(line, sizeof(line), fptr))
				{
					printf(" %d %s", c+1,line);
					c++;
				}
			}
		}
		else
			printf("USAGE: ./a.out -numlines filename t/b\n");
	}

	fclose(fptr);
	return 0;

}