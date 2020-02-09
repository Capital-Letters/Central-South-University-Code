#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int A[n][n];
        int dp[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i+1;j++)
            {
                cin>>A[i][j];
            }
        }
        for(int j=0;j<n;j++)
        {
            dp[j]=A[n-1][j];
        }
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                dp[j]=max(dp[j],dp[j+1])+A[i][j];
            }
            
        }
        cout<<dp[0]<<endl;
    }
    
    
}