#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* line = (char*)malloc(sizeof(char)*505);
	char* key = (char*)malloc(sizeof(char)*105);
	scanf("%s ",key);
	scanf(" %[^\n]", line);
	char temp[104];
	int st = 0, j=0, ct=0;
	int len = strlen(line);
	while(1){
		while(line[st]!=' ' && st != len){
			temp[j]=line[st];
			j++;
			st++;
		}
		temp[j]='\0';
		if(strcmp(temp,key)==0)
			ct++;
		st++;
		j=0;
		if(st>=len)
			break;
	}
	printf("%d\n",ct);
	free(key);
	free(line);
	return 0;
}
