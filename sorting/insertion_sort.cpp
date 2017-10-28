#include <iostream>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;
int main(){
	int n,i,temp,j;
	cin>>n;
	int a[n];
	FOR(i,n)
	{
		cin>>a[i];
	}
	FOR(i,n)
	{
		temp = a[i];
		j=i;
		while(j>0 && a[j-1]>temp){
			a[j]= a[j-1];
			j--;
		}
		swap(a[j],temp);
	}
	FOR(i,n){
		cout<<a[i]<<",";
	}
	cout<<endl;
	return 0;
}