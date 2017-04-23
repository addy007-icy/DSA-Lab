#include <stdio.h>
#include <stdlib.h>

int strlen_(char* str);
char* strcpy(char* dest, char* src);
char* strcat(char* dest, char* src);
int strend(char* s, char* t);
int checkPalindrome(char* s);
char* reverse(char* original);

int main()
{
	char *str1 = (char*)malloc(sizeof(char)*100);
	char *str2 = (char*)malloc(sizeof(char)*100);
	char* s;
	scanf("%s %s",str1,str2);
	s = strcpy(s, str1);
	//printf("%s %s\n",str1,str2);
	printf("%s\n",strcat(str1,str2));
	printf("%d\n",strend(str1,str2));
	//strend(str1,str2);
	free(str1);
	free(str2);
	return 0;
}

int strlen_(char* str)
{
	int len = 0;
	while(*str){
		*str++;
		len++;
	}
	return len;
}

char* strcpy(char* dest, char* src)
{
	dest = (char*)malloc(sizeof(char)*10);
	char* ans = dest;
	while(*src){
		*dest++ = *src++;
	}
	return ans;
}

char* strcat(char* dest, char* src)
{
	int len = strlen_(dest)+strlen_(src);
	char* res = (char*)malloc(sizeof(char)*len+5);
	char* temp = res;
	while(*dest){
		*res++ = *dest++;
	}
	do{
		*res++ = *src++;
	}while(*src);
	return temp;
}

int strend(char* s, char* t)
{
	int len1 = strlen_(t), len2 = strlen_(s), ct=0;
	while(ct<(len2-len1) && (len2>=len1)){
		*s++;
		ct++;
	}
	while(*s){
		if(*s++ != *t++)
			return 0;
	}
	return 1;
}

int checkPalindrome(char* s)
{
	int len = strlen_(s);
	char* st = s;
	char* en = s+len-1;
	while(st<en){
		if(*st!=*en)
			return 0;
		st++;
		en--;
	}
	return 1;
}

char* reverse(char* original)
{
	static char rev[100];
	static int i = 0;
	if(*original){
		reverse(original+1);
		rev[i++] = *original;
	}
	return rev;
}
