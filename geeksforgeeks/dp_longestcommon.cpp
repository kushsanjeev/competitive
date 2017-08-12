#include <iostream>
#define MAX 100
using namespace std;
int max(int , int);


int lcs(char *A, char* B, int m, int n)
{
	int L[m+1][n+1];
	int i,j;

	for(i=0;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			if(i==0||j==0)
				L[i][j] = 0;
			else if(A[i-1]==B[j-1])
				L[i][j] = 1+(L[i-1][j-1]);
			else
				L[i][j] = max(L[i-1][j],L[i][j-1]);
		}
	}

	return L[m][n];
}

int max(int a, int b)
{
	return (a>b)?a:b;
}

int main(){
	char  A[MAX];
	char B[MAX];
	scanf("%s",A);
	printf("%s",A);
	scanf("%s",B);
	printf("%s",B);
	int m = strlen(A);
	int n = strlen(B);

	printf("%d\n",lcs(A,B,m,n) );
	return 0;
}