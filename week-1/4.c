#include <stdio.h>
#include <string.h>

int main()
{
	char line[200];
	scanf(" %[^\n]",line);
	int ct = 0, i = 0, len = strlen(line);
	int st[100]={0}, en[100]={0};
	st[0]=0;
	for(int i=0; i<len; i++){
		if(line[i]==' '){
			en[ct]=i-1;
			ct++;
			st[ct]=i+1;
		}
	}
	if(en[ct]==0){
		en[ct]=len-1;
		ct++;
	}
	for(int i=0; i<ct; i++){
		int start = st[i], end = en[i];
		//printf("%d => %d %d\n", i,start,end);
		while(start<end){
			char tmp = line[start];
			line[start] = line[end];
			line[end] = tmp;
			start++;
			end--;
		}
	}
	for(int i=0; i<len; i++){
		int tmp;
		if(line[i] >= 'A' && line[i] <= 'Z'){
			tmp = line[i]-65;
			tmp = (tmp+3)%26;
			tmp = tmp+65;
			line[i] = tmp;
		}
		else if(line[i] >= 'a' && line[i] <= 'z'){
			tmp = line[i]-97;
			tmp = (tmp+3)%26;
			tmp = tmp+97;
			line[i] = tmp;
		}
	}
	printf("%s\n",line);
	return 0;
}
