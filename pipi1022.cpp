#include<bits/stdc++.h>
using namespace std;
void walk(int &x,int &y,int dic)
{
    switch (dic)
    {
    case 0:
        x--;
        break;
    case 1:
        y++;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    
    default:
        break;
    }
}
void back(int &x,int &y,int dic)
{
    switch (dic)
    {
    case 0:
        x++;
        break;
    case 1:
        y--;
        break;
    case 2:
        x--;
        break;
    case 3:
        y++;
        break;
    
    default:
        break;
    }
}
void adjustdiction(int &dic)
{
    dic=(dic+4+1)%4;
}
int main()
{
    int w,h;
    while(cin>>w>>h)
    {
        char maze[w][h];
        bool vis[w][h];
        int x,y;
        int dic;
        for(int i=0;i<w;i++)
        {
            cin>>maze[i];
        }
        for(int i=0;i<w;i++)
        {
            for(int j=0;j<h;j++)
            {
                if(maze[i][j]=='U'||maze[i][j]=='R'||maze[i][j]=='D'||maze[i][j]=='L')
                {
                    x=i;
                    y=j;
                    
                    switch (maze[i][j])
                    {
                    case 'U':
                        dic=0;
                        break;
                    case 'R':
                        dic=1;
                        break;
                    case 'D':
                        dic=2;
                        break;
                    case 'L':
                        dic=3;
                        break;
                    default:
                        break;
                    }
                }
                vis[i][j]=false;
            }
        }
        int count=1;
        do
        {
            vis[x][y]=true;
            walk(x,y,dic);
            if(0<=x&&x<w&&0<=y&&y<h&&!vis[x][y]&&maze[x][y]=='.')
            {
                count++;
            }
            else
            {
                back(x,y,dic);
                adjustdiction(dic);
                walk(x,y,dic);
                if(0<=x&&x<w&&0<=y&&y<h&&!vis[x][y]&&maze[x][y]=='.')
                {
                    count++;
                }
            }
        } 
        while (0<=x&&x<w&&0<=y&&y<h&&!vis[x][y]&&maze[x][y]=='.');
        cout<<count<<endl;
        
    }
}