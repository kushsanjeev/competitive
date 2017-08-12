#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
void seive(int n){
	int i,j;
	bool prime[n+1];
	memset(prime,true,sizeof(prime));
	for(i=2;i*i<n;i++)
	{
		if(prime[i]==1)
			for(j=2*i;j<=n;j+=i)
				prime[j]=0;
	}
	for(i=2;i<n;i++)
		if(prime[i])
			fout<<i<<","<<endl;

}
int main(){
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	int n;
	fin>>n;
	seive(n);
	return 0;
	fin.close();
	fout.close();
}