#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

struct Books {
	char name[20];
	char auname[20];
	int edition;
	int ISBN;
	long int price;
	char pub[20];
	int year;
};

int main(int argc, char* argv[])
{
	int n, i;
	time_t t;
	scanf("%d", &n);
	struct Books b[n];
	FILE *fp = fopen("test.txt", "w");

	if (fp == NULL)
	{
		printf("ERROR in opening the file\n");
		return 0;
	}
	srand(time(NULL));

	for (i = 0; i < n; i++)
	{	int x = (rand() % 2017) + 1 ;					// writing randum numbers to a file
		fprintf(fp, "%d\n", x);
		// continue;
	}
	fclose(fp);
	fp = fopen("test.txt", "r");
	char num[10];
	i=0;
	while (fgets(num,sizeof(num),fp))
	{
		b[i].year =  atoi(num);
		i++;
	}
	int size = i;
	// int c= 0;
	// while(c<size)
	// {
	// 	printf("%d\n", b[c].year);
	// 	c++;
	// }
	for(i=1;i<n;i++)
	{
		int j=i-1;
		int key = b[i].year;
		while(j>=0 && b[j].year > key)
		{
			b[j+1].year = b[j].year	;
			j--;
		}
		b[j+1].year = key;
	}
	for(i=0;i<size;i++)
		printf("%d\n", b[i].year);
	return 0;
}
