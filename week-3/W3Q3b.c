#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	FILE *fptr;
	char line[500];
	if (argc <= 2)
	{
		printf("Provide command line arguements\n");
		return 0;
	}

	else if ( strcmp(argv[1], "-x") == 0)
	{
		if (( fptr = fopen(argv[3], "r")) == NULL)
		{
			printf("Error: Can't Open File\n");
			return 0;
		}
		int count = 0;
		while (fgets(line, sizeof(line), fptr))
		{
			if ( strstr(line, argv[2]) == 0)
			{
				printf(" %d -> %s", count + 1, line);

			}
			count++;
		}
	}
	else {

		if (( fptr = fopen(argv[2], "r")) == NULL)
		{
			printf("Error: Can't Open File\n");
			return 0;
		}
		int count = 0;
		while (fgets(line, sizeof(line), fptr))
		{
			if ( strstr(line, argv[1]) != 0)
			{
				printf(" %d -> %s", count + 1, line);

			}
			count++;
		}

	}


	return 0;
}