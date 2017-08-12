#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int max(int x,int y, int z)
{
	return max(max(x,y),z);
}
int main(){
	int t,i,j,r,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		int d[r+2][c+2];
		for(i=0;i<c+2;i++)
		{
			d[0][i] = 0;
			d[r+1][i] = 0;
		}
		for(j=0;j<r+2;j++)
		{
			d[j][0]= 0;
			d[j][c+1]= 0;
		}
		for(i=1;i<r+1;i++)
		{
			for(j=1;j<c+1;j++)
			{
				cin>>d[i][j];
			}
		}
		for(i=r;i>0;i--)
		{
			for(j=c;j>0;j--)
			{
				d[i][j] +=max(d[i+1][j],
								d[i+1][j+1],
								d[i+1][j-1]);
			}
		}
		r = d[1][1];
		for(i=1;i<=c;i++)
		{
			r = max(r,d[1][i]);
		}
		cout<<r<<endl;
	}
	return 0;	
}