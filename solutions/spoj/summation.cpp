#include <iostream>
using namespace std;
 

int main()
{

    int t,i,j,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a[n];
        unsigned long long total = 1<<n;

        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        unsigned long long sum = 0;
        for(i=0;i<total;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i & (1<<j))
                    {
                        sum+=a[j]%100000007;
                        sum%=100000007;
                    }
            }
        }
        printf("%llu\n", sum );
    }
    return 0;
}