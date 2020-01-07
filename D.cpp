#include <bits/stdc++.h>
using namespace std;

const int N =1e3+5;
vector <int>  vec[N];
int S[N],ans[N];
int n,m,t,k;
bool viss[N] , vis[N];//标记集合S和bfs标记数组
bool bfs(int u)
{
	int cnt=1;
	vis[u]=true;
	queue <pair<int,int> > q;
	q.push({u,0});
	while(q.size())
	{
		pair<int,int> now=q.front();
		q.pop();
		if(now.second>=t) continue;
		for(int i=0;i<vec[now.first].size();i++)
		{
			int v = vec[now.first][i];
			if(!viss[v]) return false;//邻接点必须是S中的 
			if(!vis[v])
			{
				cnt+=1;
				vis[v] = true;
				q.push({v,now.second+1});
			}
		}
	}
	if(cnt<k) return false;
	else return true;
 } 
 int main()
 {
 	scanf("%d%d",&m,&n);
 	for(int i=1;i<m;i++)//存储邻接表 
 	{
 		int u,v;
 		scanf("%d%d",&u,&v);
 		vec[u].push_back(v);
 		vec[v].push_back(u);
	 }
	 scanf("%d%d",&k,&t);
	 for(int i=1;i<=k;i++)
	 {
	 	scanf("%d",&S[i]);
	 	viss[S[i]]=1;
	 }
	 int id=0;
	 for(int i=1;i<=k;i++)//初始化vis数组 
	 {
	 	memset(vis,0,sizeof(vis));
	 	if(bfs(S[i])) ans[id++] = S[i]; 
	 }
	 if(id==0) cout << -1;
	 sort(ans,ans+id);
	 for(int i=0;i<id;i++)
	 {
	 	if(i==id-1) printf("%d",ans[i]);
	 	else printf("%d ",ans[i]);
	 }
	 return 0;
 }
