#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int min(int x,int y,int z)
{
	return min(min(x,y),z);
}
int edit(string a, string b, int m,int n){
	int d[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0)
				d[i][j]=j;
			else if(j==0)
				d[i][j]= i;
			else if(a[i-1]==b[j-1])
				d[i][j]= d[i-1][j-1];
			else
				d[i][j]= 1 + min(d[i-1][j],
								d[i][j-1],
								d[i-1][j-1]);

		}
	}
	return d[m][n];
}
int main(){
	int m,n,ans;
	string a,b;
	cin>>a;
	cin>>b;
	m = a.size();
	n = b.size();
	ans = edit(a,b,m,n);
	printf("%d\n",ans );
	return 0;
}