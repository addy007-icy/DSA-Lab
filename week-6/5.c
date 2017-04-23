//USE: ./five < wordfile.txt | sort | ./five2 > output.txt
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(char*)a - *(char*)b );
}

int main()
{
	int n,i;
	scanf("%d",&n);
	char word[50][55], sortedWord[50][55];
	for(i=0; i<n; i++){
		scanf(" %s", word[i]);
		int len = strlen(word[i]);
		strcpy(sortedWord[i],word[i]);
		qsort(sortedWord[i],len,sizeof(char),cmpfunc);
		printf("%s %s\n",sortedWord[i], word[i]);
	}
	return 0;
}
