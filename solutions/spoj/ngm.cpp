#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	if(t%10==0)
	{
		cout<<"2"<<'\n';
	}
	else{
		cout<<'1'<<'\n';
		cout<<(t%10)<<'\n';
	}
	return 0;
}