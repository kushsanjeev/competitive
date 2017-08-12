#include <iostream>
#include <vector>
#include <string>
using namespace std;
string s;
vector<int> vec;
int main(){
	int res = 0,i,n;
	while(getline(cin,s)){
		vec.clear();
		for(i=0;i<s.size();i++)
		{
			if(s[i]==EOF)
				vec.push_back(res);
			else
			{
				res = res*10+(s[i]-'0');
			}
		}
		vec.push_back(res);
		for(i=0;i<vec.size();i++)
		{
			if(vec[i]==1)
				printf("%d\n",1);
			else
				printf("%d\n",2*vec[i]-2 );
		}
	}
		return 0;

}