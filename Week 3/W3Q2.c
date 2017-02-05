#include "stdio.h"
#include "stdlib.h"
#include "string.h"

char* getSoundEx(char* s)
{
  int i, len = strlen(s);
  for(i = 0; i < len; i++)
  {
    if(s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
    char c = s[i];
    if(i==0)continue;
    if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='H'||c=='W'||c=='Y') c = '0';
    if(c=='B'||c=='F'||c=='P'||c=='V') c = '1';
    if(c=='C'||c=='G'||c=='J'||c=='K'||c=='Q'||c=='S'||c=='X'||c=='Z') c = '2';
    if(c=='D'||c=='T') c = '3';
    if(c=='L') c = '4';
    if(c=='M'|| c=='N') c = '5';
    if(c=='R') c = '6';
    s[i] = c;
  }
  char *s2 = (char*)malloc(sizeof(char)*1000);
  int j = 0;
  s2[0]=s[0];
  for(i = 1; i < len; i++){
    if(s[i]!=s2[j]){
      s2[++j]=s[i];
    }
  }
  s2[++j]='\0';
  j=0,len=strlen(s2);
  for(i = 0; i < len; i++){
    if(s2[i] != '0'){
      s[j++]=s2[i];
    }
  }
  while(j<4) s[j++]='0';
  if(j > 4) j = 4;
  s[j]='\0';
  return s;
}
int main(){
	FILE *file;
  file = fopen("test.txt","r");
  
  char *s=(char*)malloc(100*sizeof(char));
  scanf("%s", s);
  s = getSoundEx(s);
  
  char buf[10000],c;
  char *word = (char*)malloc(sizeof(char)*100);
  
  while(fgets(buf,5000,file))
  {
    int i=0,j=0,len=strlen(buf);
    int printThis=0;
    while(i<len)
    {
      j=0;
      while(!(buf[i]==' ' || buf[i]=='\0' || buf[i]=='.'))
      {
        word[j++]=buf[i++];
      }word[j]='\0';
      if(word[j-1]=='.') word[--j]='\0';
      
      word = getSoundEx(word);
      if(strcmp(word,s)==0) printThis = 1;
      
      i++;
    }
    if(printThis == 1) printf("%s", buf);
  }
  fclose(file);
	return 0;
}