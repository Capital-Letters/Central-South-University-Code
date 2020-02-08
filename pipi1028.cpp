#include<bits/stdc++.h>
using namespace std;
char maze[100][100];
bool vis[100][100];
typedef struct {
    int x,y;
    int dic;
    int turn;
}node;
queue <node> Q;
void bfs(int x1,int y1,int x2,int y2,int m,int n,int &min)
{
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            vis[i][j]=false;
        }
    }
    vis[x1][y1]==true;
    node start;
    start.x=x1;
    start.y=y1;
    start.dic=0;
    start.turn=-1;
    Q.push(start);
    while(!Q.empty())
    {
        node cur=Q.front();
        int curx=cur.x;
        int cury=cur.y;
        Q.pop();
        // cout<<"x="<<curx<<" y="<<cury<<" dic="<<cur.dic<<" turn="<<cur.turn<<endl;
        if(curx==x2&&cury==y2)
        {
            if(cur.turn<min) min=cur.turn;
            // cout<<"min="<<min<<endl;
        }
        //往上走
        if(0<=curx-1&&curx-1<m&&0<=cury&&cury<n&&vis[curx-1][cury]==false&&maze[curx-1][cury]=='.')
        {
            node next;
            next.x=curx-1;
            next.y=cury;
            next.dic=1;
            vis[curx-1][cury]=true;
            if(cur.dic!=next.dic)
            {
                next.turn=cur.turn+1;
            }
            Q.push(next);
        }
        //往右走
        if(0<=curx&&curx<m&&0<=cury+1&&cury+1<n&&vis[curx][cury+1]==false&&maze[curx][cury+1]=='.')
        {
            node next;
            next.x=curx;
            next.y=cury+1;
            next.dic=2;
            vis[curx][cury+1]=true;
            if(cur.dic!=next.dic)
            {
                next.turn=cur.turn+1;
            }
            Q.push(next);
        }
        //往下走
        if(0<=curx+1&&curx+1<m&&0<=cury&&cury<n&&vis[curx+1][cury]==false&&maze[curx+1][cury]=='.')
        {
            node next;
            next.x=curx+1;
            next.y=cury;
            next.dic=3;
            vis[curx+1][cury]=true;
            if(cur.dic!=next.dic)
            {
                next.turn=cur.turn+1;
            }
            Q.push(next);
        }
        //往左走
        if(0<=curx&&curx<m&&0<=cury-1&&cury-1<n&&vis[curx][cury-1]==false&&maze[curx][cury-1]=='.')
        {
            node next;
            next.x=curx;
            next.y=cury-1;
            next.dic=4;
            vis[curx][cury-1]=true;
            if(cur.dic!=next.dic)
            {
                next.turn=cur.turn+1;
            }
            Q.push(next);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int m,n;
        cin>>m>>n;
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<n;k++)
            {
                cin>>maze[j][k];
            }
        }
        int k,x1,y1,x2,y2;
        cin>>k>>y1>>x1>>y2>>x2;
        y1--;
        x1--;
        y2--;
        x2--;
        if(maze[x1][y1]=='*'||maze[x2][y2]=='*')
        {
            cout<<"no"<<endl;
            continue;
        }
        while(!Q.empty()) Q.pop();
        int min=10;
        bfs(x1,y1,x2,y2,m,n,min);
        if(min<=k) 
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        
    }
}