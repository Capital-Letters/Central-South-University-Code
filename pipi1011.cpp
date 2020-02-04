#include<bits/stdc++.h>
#define max 1001
#define INF 65536
using namespace std;
int weight[max];
bool vis[max];
int MG[max][max];
int N;
void dijstra(int S,int T)
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=N;i++)
    {
        weight[i]=MG[S][i];
    }
    weight[S]=INF;
    int min_arc,min_vex;
    for(int i=1;i<=N;i++)
    {
        int min_arc=INF;
        for(int j=1;j<=N;j++)
        {
            if(!vis[j]&&weight[j]<min_arc)
            {
                min_vex=j;
                min_arc=weight[j];
            }
        }
        vis[min_vex]=true;
        for(int j=1;j<=N;j++)
        {
            if(!vis[j]&&weight[min_vex]+MG[min_vex][j]<weight[j])
            {
                weight[j]=weight[min_vex]+MG[min_vex][j];
            }
        }
    }
}
int main()
{
    int M,S,T,A;
    while (cin>>N>>M>>S>>T>>A)
    {
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
            {
                MG[i][j]=INF;
            }
        }
        int u,v,t;
        for(int i=0;i<M;i++)
        {
            cin >> u >> v >> t;
            if(u%2==0)  MG[u][v]=t+2;
            else MG[u][v]=t+1;
            if(v%2==0) MG[v][u]=t+2;
            else MG[v][u]=t+1;
        }
        dijstra(S,T);
        int cost=weight[T];
        if(cost<=A) cout << "YES " << cost;
        else
        {
            cout << "KENG";
        }
        cout << endl;
    }
    
}