// #include<bits/stdc++.h>
// using namespace std;
// double A[1005][1005];
// int main()
// {
//     int n;
//     while(cin>>n)
//     {
//         double safe;
//         for(int i=1;i<=n;i++)
//         {
//             for(int j=1;j<=n;j++)
//             {
//                 cin>>safe;
//                 A[i][j]=safe;
//             }
//         }
//         for(int k=1;k<=n;k++)
//         {
//             for(int i=1;i<=n;i++)
//             {
//                 for(int j=1;j<=n;j++)
//                 {
//                     if(A[i][k]*A[k][j]>A[i][j]) 
//                     {
//                         A[i][j]=A[i][k]*A[k][j];    
//                     }
//                 }
//             }
//         }
//         int num,x,y;
//         cin >> num;
//         for(int i=1;i<=num;i++)
//         {
//             cin>> x >> y;
//             if(A[x][y]==0)
//             {
//                 cout << "What a pity!" << endl;
//             }
//             else
//             {
//                 printf("%.3lf\n",A[x][y]);
//             }
//         }
//     }
// }
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
double MG[MAX][MAX];
double weight[MAX];
bool vis[MAX];
int n;
int dij(int x,int y)
{
    memset(vis,false,sizeof(vis));
    fill(weight,weight+MAX,0);
    weight[x]=1;
    if(x==y) return 1;
    double max_arc;
    int max_vex=-1;
    for(int i=1;i<=n;i++)
    {
        int max_arc=0;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&weight[j]>max_arc)
            {
                max_vex=j;
                max_arc=weight[j];
            }
        }
        if(max_vex==-1) return -1;
        if(max_vex==y) return 1;
        vis[max_vex]=true;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&MG[j][max_vex]!=0&&weight[j]<MG[j][max_vex]*weight[max_vex])
            {
                weight[j]=MG[j][max_vex]*weight[max_vex];
            }
        }
    }
}
int main()
{
    while (cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cin>>MG[i][j];
            }
        }
        int num;
        int x,y;
        cin>>num;
        for(int i=0;i<num;i++)
        {
            cin >> x >> y;
            int res=dij(x,y);
            if(res==-1) cout << "What a pity!"<<endl;
            else
            {
                printf("%.3lf\n",weight[y]);
            }
            
        }
    }
    
}