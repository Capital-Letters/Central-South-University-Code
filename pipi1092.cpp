#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int A[n];
        for(int i=0;i<n;i++)
        {
            cin>>A[i];
        }
        int dp[n];
        dp[0]=A[0];
        dp[1]=max(A[0],A[1]);
        for(int i=2;i<n;i++)
        {
            dp[i]=max(dp[i-2]+A[i],dp[i-1]);
        }
        cout << dp[n-1] << endl;
    }
}