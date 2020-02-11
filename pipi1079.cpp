#include<bits/stdc++.h>
#define INF 1e9
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int f[m],val[n],cost[n];
        for(int i=1;i<=n;i++)
        {
            cin>>val[i]>>cost[i];
        }
        for(int i=0;i<=m;i++) f[i]=INF;
        f[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=cost[i];j<=m;j++)
            {
                f[j]=min(f[j-cost[i]]+val[i],f[j]);
            }
        }
        if(f[m]==INF) cout << "impossible";
        else cout << f[m];
        cout << endl;
    }
}