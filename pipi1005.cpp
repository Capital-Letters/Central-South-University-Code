// #include<bits/stdc++.h>
// #define MAX_INT 999999;
// using namespace std;
// int main()
// {
//     int n,m;
//     while(scanf("%d%d",&m,&n)==2)
//     {
//         int a,b,v;
//         int cost=0;
//         vector<vector<int>> G(m,vector<int>(m));
//         for(int k=0;k<n;k++)
//         {

//             cin>>a>>b>>v;
//             G[a][b]=v;
//             G[b][a]=v;
//         }
//         int min_weight[m];
//         for(int i=1;i<m;i++)
//         {
//             min_weight[i]=G[0][i];
//         }
//         for(int i=1;i<m;i++)
//         {
//             int min_arc=MAX_INT;
//             int min_vex;
//             for(int j=1;j<m;j++)
//             {
//                 if(min_weight[j]!=0&&min_weight[j]<min_arc)
//                 {
//                     min_arc=min_weight[j];
//                     min_vex=j;
//                 }
//             }

//             cost+=min_weight[min_vex];
//             min_weight[min_vex]=0;
//             for(int j=0;j<m;j++)
//             {
//                 if(min_weight[j]!=0&&G[min_vex][j]<min_weight[j])
//                 {
//                     min_weight[j]=G[min_vex][j];
//                 }
//             }
//         }
//         if(n<m-1) cout << "?" << endl;
//         else
//         {
//             cout << cost <<endl;
//         }
        
//     }
    
// }
#include<iostream>
#include<stdio.h> 
#include<algorithm>
using namespace std;
/*要畅通，就必需要m-1条边，要使费用最小则尽量用权值最小的变，先对所有的边进行排序
然后从小到大依次选择，判断该边是否可以加入此工程,判断的方法是使用并查集*/
int n, m;
int arr[105];
struct node
{
    int start, end, w;
}a[5010];

int cmpare(node x, node y)
{
    return x.w<y.w;
}

int find(int x){
    while(arr[x]!=x){
        x=arr[x];
    }
    return x;
}

int add(int x,int y){
    int x1=find(x);
    int y1=find(y);
    if(x1!=y1){
        arr[x1]=y1;
        return 1;
    }
    return 0;
}
int main(){
    while (scanf("%d%d", &m, &n) != EOF){
        for (int i = 0; i < n; i++){
            scanf("%d%d%d", &a[i].start, &a[i].end, &a[i].w);
        }
        sort(a, a + n, cmpare);
        for (int i = 1; i <=m; i++){
            arr[i] = i;
        }
        int num = 0;
        int result = 0;
        for (int i = 0; num < m - 1 && i < n; i++){
            if (add(a[i].start,a[i].end)){
                num++;
                result += a[i].w;
            }
        }
        if (num == m - 1){
            printf("%d\n", result);
        }
        else{
            printf("?\n");
        }
    }
}