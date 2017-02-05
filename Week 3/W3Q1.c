#include <stdio.h>
#include <string.h>

char* arr[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char* brr[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
char* crr[] = {"x","x","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char* drr[] = {"Hundred","Thousand"};

void solve(char* num){
	int i=0, flag =0, len = strlen(num);
	if(len>3 && len < 7){
		flag = 0;
		if(len == 6){
			if(num[i]-'0' != 0){
				printf("%s %s ",arr[num[i]-'0'],drr[0]);
				flag = 1;
			}
			i++;
			len--;
		}
		if(len == 5 && (num[i]-'0')==1){
			printf("%s ",brr[num[i+1]-'0']);
			flag= 1;
			i = i+2;
		}
		else if(len ==5 ){
			if(num[i]-'0' != 0)	{
				printf("%s ",crr[num[i]-'0']);
				flag= 1;
			}
			if(num[i+1]-'0') {
				printf("%s ",arr[num[i+1]-'0']);
				flag= 1;
			}
			i = i+2;					
		}
		else{
			printf("%s ",arr[num[i]-'0']);
			flag= 1;
			i++;
		}
		if(flag == 1)
			printf("%s ",drr[1]);
		len=3;
		flag = 1;
	}
	if(len<4){
		 if(len == 3){
			 if(num[i]-'0' != 0){
			 	if(num[i+1]-'0'==0 && num[i+2]-'0'==0)
			 		printf("%s %s ",arr[num[i]-'0'],drr[0]);
		 		else
		 			printf("%s %s and ",arr[num[i]-'0'],drr[0]);
			 }
			 else if(flag == 1 && (num[i]-'0'!=0 || num[i+1]-'0'!=0 || num[i+2]-'0'!=0))
			 	printf("and ");
			 i++;
			 len--;
		}
		if(len == 2 && (num[i]-'0')==1){
			printf("%s ",brr[num[i+1]-'0']);
		}
		else if(len == 2){
			if(num[i]-'0' != 0)
				printf("%s ",crr[num[i]-'0']);
			if(num[i+1]-'0' != 0)	
				printf("%s ",arr[num[i+1]-'0']);			
		}
		else{
			printf("%s",arr[num[i]-'0']);
		}
		i+=2;
		len-=3;
	}
	printf("\n");
}
int main(){
	int t,n;
	char inp[10];
	scanf("%s",inp);
	solve(inp);
	return 0;
}

