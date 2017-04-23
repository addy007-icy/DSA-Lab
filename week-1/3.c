#include <stdio.h>
#include <string.h>

typedef struct 
{
	char letter;
	int ct;
	int fl;
}freq;

int main()
{
	char line[200];
	scanf(" %[^\n]",line);
	int i = 0, len = strlen(line);
	freq list[129];
	for(int i=0; i<=127; i++){
		list[i].letter = (char)i;
		list[i].ct = list[i].fl = 0;
		//printf("%d => %c\n", i,list[i].letter);
	}
	for(i; i<len; i++){
		list[line[i]].ct = list[line[i]].ct + 1;
	}
	for(i=0; i<len; i++){
		if(list[line[i]].fl == 0){
			printf("%c %d\n",list[line[i]].letter, list[line[i]].ct);
			list[line[i]].fl = 1;
		}
	}
	return 0;
}
