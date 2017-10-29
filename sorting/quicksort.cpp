/* complexity 
worst case = O(n^2)
average case = O(nlogn)
*/
#include <iostream>
#define FOR(i,n) for(i=0;i<n;i++)
using namespace std;

int _partition(int v[], int left, int right){
	int pivot = v[right];
	int i = left-1;
	for(int j=left;j<=right-1;j++){
		if(v[j] <= pivot){
			i++;
			swap(v[i], v[j]);	
		}
	}
	swap(v[i+1], v[right]);
	return i+1;
}

void _quick(int v[], int left, int right){
	if(left < right){
		int partition_index = _partition(v, left, right);
		_quick(v, left, partition_index - 1);
		_quick(v, partition_index + 1, right);
	}
}

void quick_sort(int length, int v[]){
	_quick(v, 0, length - 1);
}
int main(){
    int n,i;
    cin>>n;
    int v[n];
    FOR(i,n)
        cin>>v[i];
    quick_sort(n,v);
    FOR(i,n)
        cout<<v[i]<<",";
    cout<<endl;
    return 0;
}