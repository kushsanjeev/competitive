//complexity = O(n^2)
#include <stdio.h>
int main()
{
int n; 
scanf("%d",&n);
int arr[n]; 
int i;

for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}

int j,k,count=0;
for(j=0;j<n-1;j++){
	for(k=0;k<n-j-1;k++){
		if(arr[k]>arr[k+1]){
			int temp,a;
			temp=arr[k];
			arr[k]=arr[k+1];
			arr[k+1]=temp;
			count++;
		}
	}
}
for(i=0;i<n;i++){
	printf("%d, ",arr[i]);
}
printf("\nThe total number of swaps are %d\n",count);

return 0;
}