#include <stdio.h>
#include <stdlib.h>

struct trie {
	struct trie *nodes[27];
	int isleaf;
};

int getCharCode(char c){
	int code = 0;
	if(c>=65 && c<=90){
		code = c - 64;
	}
	if(c>=97 && c<=122){
		code = c - 96;
	}
	return code;
}

int main(){
	char c;
	scanf("%c",&c);
	int code = getCharCode(c);
	printf("Code: %d\n",code);
	return 0;
}