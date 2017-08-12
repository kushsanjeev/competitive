#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		if(a==b)
		{
			if(a%2==0)
				printf("%d\n",2*a );
			else
				printf("%d\n",2*a-1 );
		}
		else if(a==b+2)
		{
			if(b%2==0)
				printf("%d\n",a+b);
			else 
				printf("%d\n",2*b+1);
		}
		else
			printf("No Number\n");
	}
	return 0;
}