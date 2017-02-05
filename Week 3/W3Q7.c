#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void wc(FILE* file,int testcase)
{
	int linecount=0;
	int wordcount=0;
	int charcount=0;
	char *buf = (char*)malloc(sizeof(char)*1000);
	while(fgets(buf,500,file))
	{
		linecount++;
		int i,len=strlen(buf);
		charcount += len;
		buf[len]=' ';
		buf[++len]='\0';
		for(i=0;i<len;i++)
		{
			if(buf[i]==' '&&buf[i+1]!=' ') wordcount++;
		}
	}
	printf("File #%d:\n",testcase);
	printf("Line Count : %d\n", linecount);
	printf("Word Count : %d\n", wordcount);
	printf("Character Count : %d\n", charcount);
	printf("-----------------");
}
int main(int argc, char* argv[])
{
	int i;
	for(i=1;i<=argc;i++)
	{
		FILE *file;
		file=fopen(argv[i],"r");
		wc(file,i);
		fclose(file);
	}
	return 0;
}