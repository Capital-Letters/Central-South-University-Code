#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int a[110][110];
//结构体重载，队列的优先规则
struct node{
    friend bool operator < (node n1, node  n2 )
    {
        return n1.h>n2.h;
    }
    int x;
    int y;
    int h;
};
//node按h入对列从小到大排序,s.top() 即为最小h的=所在
priority_queue<node>q;
int r,c,i,j,k;
int dp[110][110];//dp【i】【j】表示从i，j出发可以滑行区域的最大值


int main()
{
	cin>>r>>c;
	k=1;
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			cin>>a[i][j];
			node w;
			w.x=i;w.y=j;w.h=a[i][j];
			q.push(w);
			//，dp【i】【j】的初始值为1；
			dp[i][j]=1;
		}
	}
	while(!q.empty())
    {
        int ax=q.top().x;
        int ay=q.top().y;
        q.pop();
        if(ax+1<=r&&a[ax+1][ay]>a[ax][ay])
        {
            dp[ax+1][ay]=max(dp[ax+1][ay],dp[ax][ay]+1);
        }
        if(ay+1<=c&&a[ax][ay+1]>a[ax][ay])
        {
            dp[ax][ay+1]=max(dp[ax][ay+1],dp[ax][ay]+1);
        }
        if(ax-1>=1&&a[ax-1][ay]>a[ax][ay])
        {
            dp[ax-1][ay]=max(dp[ax-1][ay],dp[ax][ay]+1);
        }
        if(ay-1>=1&&a[ax][ay-1]>a[ax][ay])
        {
            dp[ax][ay-1]=max(dp[ax][ay-1],dp[ax][ay]+1);
        }
    }
    //查找dp中的最大值
        int ma=dp[1][1];
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(dp[i][j]>ma)
                ma=dp[i][j];
            }
        }
        cout<<ma<<endl;
        return 0;
}