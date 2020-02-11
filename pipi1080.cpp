#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int A[n];
        for(int i=1;i<=n;i++)
        {
            cin >> A[i];
        }
        int d[n];
        d[1]=1;
        for(int i=2;i<=n;i++)
        {
            int j;
            int flag=0;
            int max=0;
            for(j=i-1;j>=1;j--)
            {
                if(A[i]>A[j])
                {
                    flag=1;
                    if(d[j]>max) max=d[j];
                }
            }
            if(flag)
            {
                d[i]=max+1;
            }
            else
            {
                d[i]=1;
            }
            
        }
        int max=1;
        for(int i=1;i<=n;i++)
        {
            if(d[i]>d[max]) max=i;
        }
        cout << d[max] << endl;
    }
}