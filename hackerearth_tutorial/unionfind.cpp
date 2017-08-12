#include <iostream>
#include <stdio.h>
using namespace std;
int size[100];
void initialise(int arr[],int N)
{
	for(int i=0;i<N;i++)
	{
		arr[i]= i;
		size[i] = 1;
	}
}
int root(int arr[],int i){
	while(arr[i]!=i)
	{
		arr[i]=arr[arr[i]];//path compression
		i = arr[i];
	}
	return i;
}
void wu(int arr[],int A, int B){
	int roota = root(arr,A);
	int rootb = root(arr,B);
		if(size[roota]<size[rootb])
		{
			arr[roota]=arr[rootb];
			size[rootb]+=size[roota];//size helps in keeping tree balanced making union and find function work in logN time.
		}
		else
		{
			arr[rootb]= arr[roota];
			size[roota]+=size[rootb];
		}
}
void find(int arr[],int a,int b)
{
	if(root(arr,a)==root(arr,b))
	{
		cout<<"yes"<<endl;
	}
	else
		cout<<"no"<<endl;
}
int main(){
	int N,i,x=1,choice,a,b;
	cin>>N;
	int arr[N];
	for(i=0;i<N;i++)
	{
		cin>>arr[i];
	}
	initialise(arr,N);
	cout<<"values entered"<<endl;
	while(x)
	{
		cout<<"Enter choice 1.union 2.find 3.exit ";
		cin>>choice;
		switch(choice)
	{
		case 1:
			cin>>a>>b;
			wu(arr,a,b);
			break;
		case 2:
			cin>>a>>b;
			find(arr,a,b);
			break;
		case 3:
			x = 0;
	}
	}
return 0;
}