#include <stdio.h>

int main()
{
	int m, p, n, i, j, k;
	scanf("%d %d", &m, &p);
	int a[m][p];
	for(i=0; i<m; i++){
		for(j=0; j<p; j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d", &p, &n);
	int b[p][n];
	for(i=0; i<p; i++){
		for(j=0; j<n; j++){
			scanf("%d",&b[i][j]);
		}
	}
	int c[m][n], sum = 0, temp = 0;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++){
			for(k=0; k<p; k++){
				temp += a[i][k]*b[k][j];
			}
			c[i][j] = temp;
			temp = 0;
			sum += c[i][j];
		}
	}
	printf("%d\n",sum);
	return 0;
}
