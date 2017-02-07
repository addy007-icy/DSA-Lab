#include<stdio.h>
int mat[6][6];
int Cardinality[36][3];
int scan_matrix()
{
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			scanf("%d",&mat[i][j]);
		}
	}
}

int counter()
{
	int a=0;
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			if(mat[i][j]!=0)
			{
				Cardinality[a][0]=i;
				Cardinality[a][1]=j;
				Cardinality[a][2]=mat[i][j];
				a++;
			}
		}
	}
	return a;
}

int check()
{
	int count = counter();
	return count;
}
int transpose()
{
	int i,j;
	for(i=0;i<6;i++)
	{
		for(j=0;j<i;j++)
		{
			int temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}
}
int main()
{
	scan_matrix();
	int count = check();
	if(count<=10)
	{
		int i;
		for(i=0;i<count;i++)
		{
			printf("%d %d %d\n",Cardinality[i][0],Cardinality[i][1],Cardinality[i][2]);
		}
		transpose();
		check();
		printf("\n\n\n");
		for(i=0;i<count;i++)
		{
			printf("%d %d %d\n",Cardinality[i][0],Cardinality[i][1],Cardinality[i][2]);
		}

	}
else
	{
		printf("Not A Sparse Matrix");
	}
	return 0;
}