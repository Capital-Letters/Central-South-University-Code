#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int height;
        int count=0;
        int A[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&height);
            int j;
            if(i==0) A[count++]=height;
            else
            {
                for(j=0;j<count;j++)
                {
                    if(height<=A[j])
                    {
                        A[j]=height;
                        break;
                    }
                }
                if(j>=count) A[count++]=height;
            }
            
        }
        printf("%d\n",count);
    }
}