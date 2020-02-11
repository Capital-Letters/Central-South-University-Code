#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        long long int dp[n+1][n+1];
        for(int i=0;i<=n;i++) dp[i][0]=1;
        for(int i=0;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) dp[i][j]=dp[i][j-1];
                else
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        cout << dp[n][n] << endl;
    }
}