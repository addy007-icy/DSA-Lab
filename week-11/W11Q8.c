#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct point{
	int x;
	int y;
};

int compareX(const void* a,const void* b)
{
	struct point* p1 = (struct point*)a;
	struct point* p2 = (struct point*)b;
	return (p1->x - p2->x);
	
}


int compareY(const void* a,const void* b)
{
	struct point* p1 = (struct point*)a;
	struct point* p2 = (struct point*)b;
	return (p1->y - p2->y);
}

float min(float x,float y)
{
	if(x<y)
		return x;
	return y;
}

float dist(struct point p1,struct point p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

float brute(struct point P[],int start,int n)
{
	float mini =10000.0;
	int i = start;
	int j;
	for(i=start;i<start+n;i++)
	{
		for(j=i+1;j<start+n;j++)
		{
			float tt = dist(P[i],P[j]);
			mini = min(tt,mini);
		}
	}
	return mini;
}

float close_ptsX(struct point* P[],int end,int start)
{
	if(end-start<=3)
		return brute(P,start,end-start);
	int mid = start+(end-start)/2;
	float kadamba1 = close_ptsX(P,mid,start);
	float kadamba2 = close_ptsX(P,end,mid+1);
	
	return min(kadamba1,kadamba2);
		
}

float sortX(struct point* P[],int n)
{
	qsort(P,n,sizeof(struct point*),compareX);
		printpts(P,n);

	float x = close_ptsX( P,n-1,0);
	
	qsort(P,n,sizeof(struct point),compareY);
	printpts(P,n);
	float y = close_ptsX( P,n-1,0);
	
	return min(x,y);

}

void printpts(struct point P[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d %d\n",P[i].x,P[i].y);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;//,j;
	struct point P[n];
	for(i=0;i<n;i++)
	{
		struct point* temp; 
		//P[i]=NULL;
		int a,b;
		scanf("%d %d",&a,&b);
		temp->x=a;
		temp->y=b;
		P[i].x=a;
		P[i].y=b;// = temp;
		//scanf("%d",&(P[i]->y));
	}
	printpts(P,n);
	
	float ans = sortX(P,n); 
	printf("%f",ans);
	
}
