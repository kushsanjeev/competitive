#include <stdio.h>
 
const int MAX = 10001;
 
int main()
{
	int edges, x, y, testcase, count;
	scanf("%d", &testcase);
	while(testcase--)
	{
	    int city[10001]={0};
		scanf("%d", &edges);
		
		for(int i = 0;i < edges;++i)
		{
			scanf("%d %d", &x, &y);
			city[x] = 1;
			city[y] = 1;
		}
		count = 0;
		for(int i = 1;i <= MAX;++i)
			if( city[i] == 1 ) 
				count++;
	
		printf("%d\n",count);
	}
	return 0;
}