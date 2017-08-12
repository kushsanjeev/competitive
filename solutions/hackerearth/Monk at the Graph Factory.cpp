#include <iostream>
using namespace std;
int main(){
	int t,i,n,sd=0,d;
	scanf("%d",&n);
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&d);
			sd+=d;
		}
		if((sd/2)+1==n)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}