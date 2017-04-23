#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
	return (*(char *)a - *(char *)b);
}

int main() {
    int i,len,j,k=0,t;
    scanf("%d",&t);
    char word[200],ch;
	while(t--){
		scanf("%s",word);
		len=strlen(word);
		for(i=len-1;i>0;i--){
		    if(word[i]>word[i-1])
		        break;
		}
		if(i==0){
		    printf("game terminated!\n");
		}
		else{
		    for(j=len-1;j>0;j--)
		        if(word[j]>word[i-1])
		            break;
		    ch=word[j];
		    word[j]=word[i-1];
		    word[i-1]=ch;
		    qsort(word+i,strlen(word+i),sizeof(char),compare);
		    printf("%s\n",word);
		}
	}
    return 0;
}

