#include <stdio.h>
#include <string.h>

int main()
{
	char str[105];
	char key[] = "goodbye"; 
	int i=0, j=0;
	scanf("%s", str);
	int len = strlen(str);
	for(i=0; i<len; i++){
		if(str[i] == key[j]){
			j++;
		}
		if(j == 7){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
