#include <stdio.h>
#include <string.h>

void reverse(char* st, char* en)
{
	char tmp;
	while(st < en){
		tmp = *st;
		*st++ = *en;
		*en-- = tmp;
	}
}

int main()
{
	char line[1005];
	scanf("%[^\n]",line);
	int len = strlen(line);
	reverse(line,line+len-1);
	int lo=0,hi,i;
	for(i=0; i<len; i++){
		if(line[i]==' '){
			hi = i-1;
			reverse(line+lo,line+hi);
			lo = i+1;
		}
		else if(i==len-1){
			hi = i;
			reverse(line+lo,line+hi);
		}
	}
	printf("%s\n",line);
	return 0;
}
