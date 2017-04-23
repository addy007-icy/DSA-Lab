#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lenw;

int check(char *temp, char word[][20], int w)
{
	int i, c = 0;

	// for (i = 0; i < w; i++)
	// {
	// 	printf("word %s\n", word[i]);
	// }

	for (i = 0; i < w; i++)
	{	
		if (strstr(temp, word[i]) != NULL)
		{
			++c;
		}
	}
	//printf("c = %d\n", c);
	
	return c;
}

int main()
{

	int i, j, k, n, c;
	char arr[100];
	scanf("%s", arr);
	n = strlen(arr);
	int w;
	scanf("%d %d", &w, &lenw);
	char word[w][20];						//whenver initialising the 2d char array always give number of columns as large number


	for (i = 0; i < w; i++)
	{
		scanf("%s", word[i]);
	}


	// for (i = 0; i < w; i++)
	// {
	// 	printf("word %s\n", word[i]);
	// }

	int x = w * lenw;

	for (i = 0; i < x, i < n , x <= n; i++, x++)
	{
		int c;
		char temp[x];
		for (j = i, c = 0; j < x; j++, c++)
		{
			temp[c] = arr[j];
		}

		//printf("temp = %s\n", temp);
		int l = 0;
		l = check(temp, word, w);

		if(l == w)
		{
		printf("string = %s start = %d end = %d\n", temp, i, i + w * lenw - 1);
		}
	}

}