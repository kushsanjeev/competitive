#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	long long int t,a,n;
	a=0;
	scanf("%lli",&t);
	while(t--)
	{
		scanf("%lli",&n);
		a = a^n;
	}
	printf("%lli\n", a);
	return 0;
}