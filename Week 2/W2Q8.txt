#include<stdio.h>


int main()
{
    FILE *fp,*ft;
    char ch;
    char file1[100],file2[100];
    scanf("%s",file1);
    scanf("%s",file2);
    fp=fopen(file1,"r");
    ft=fopen(file2,"w");
    
    while(1)
    {
            ch=fgetc(fp);
            if(ch==EOF)
                    break;
            if(ch=='/')
            {
                    ch=fgetc(fp);
                    if(ch=='*')
                    {
                        flag=0;
                        ch=fgetc(fp);
                    }
            }
            else if (ch=='*')
            {
                    ch=fgetc(fp);
                    if(ch=='/')
                    {
                        flag=1;
                        ch=fgetc(fp);
                    }
            }
            if(flag)
            {
                    putc(ch,ft);
            }
    }
    fclose(fp);
    fclose(ft);
return 0;
 }