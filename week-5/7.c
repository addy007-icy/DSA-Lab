#include <stdio.h>
#include <string.h>

int main()
{
	char str[1005], tmp1[1005], tmp2[1005], ans[1005];
	scanf("%s",str);
	int len = strlen(str),i,j,k,l,idx,max=0,tmpLen,fl;
	for(i=0; i<len; i++){
		int st=i, maxLen=len-i;
		for(j=maxLen; j>=1; j--){
			idx=0, fl=0;
			for(k=st; k<st+j; k++){
				tmp1[idx++]=str[k];
			}
			tmp1[idx]='\0';
			tmpLen = strlen(tmp1);
			if(tmpLen <= max)
				continue;
			//printf("%s  => ",tmp1);
			for(k=st+1; k<len; k++){
				if(k+tmpLen-1 >= len)
					break;
				idx = 0;
				for(l=k; l<k+tmpLen; l++){
					tmp2[idx++] = str[l];
				}
				tmp2[idx]='\0';
				//printf("%s  ",tmp2);
				if(strcmp(tmp1,tmp2)==0){
					max = tmpLen > max? tmpLen:max;
					strcpy(ans,tmp1);
					fl = 1;
					break;
				}
			}
			//printf("\n\n");
			if(fl)
				break;
		}
	}
	printf("%s\n",ans);
	return 0;
}
