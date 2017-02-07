#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int i;
	char* fileName = argv[1];
	FILE* fp = fopen(fileName,"r");
	char ch,contents[50][100];
	int r=0, c=0;
	do{
		ch = (char)fgetc(fp);
		if(ch == -1){
			contents[r][c] = '\0';
		}
		else if(ch == '\n'){
			contents[r][c] = '\0';
			r++;
			c=0;
		}
		else{
			contents[r][c++] = ch;
		}
	}while(ch != EOF);
	fclose(fp);
	fp = fopen(fileName,"w");
	int numLines = r;
	char tmp[104];
	for(i=0; i+1<numLines; i+=2){
		strcpy(tmp,contents[i]);
		strcpy(contents[i],contents[i+1]);
		strcpy(contents[i+1],tmp);
	}
	for(i=0; i<r; i++){
		int j = 0;
		while(1){
			ch = contents[i][j++];
			if(ch == 0 && i!=r){
				fprintf(fp,"\n");
				break;
			}
			else{
				fprintf(fp,"%c",ch);
			}
		}
		//printf("%s\n",contents[i]);
	}
	fclose(fp);
	return 0;
}
