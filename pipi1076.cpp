#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int A[n];
        int money;
        for(int i=0;i<n;i++)
        {
            cin >> A[i];
        }
        cin>>money;
        int dp[money];
        sort(A,A+n);
        for(int i=0;i<money;i++) dp[i]=0;
        if(money-5<0) cout << money << endl;
        else
        {
            for(int i=0;i<n-1;i++)
            {
                for(int j=money-5;j>=A[i];j--)
                {
                    dp[j]=max(dp[j],dp[j-A[i]]+A[i]);
                }
            }
            cout << money-dp[money-5]-A[n-1] << endl;
        }
        
    }
}
