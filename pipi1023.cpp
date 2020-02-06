#include<bits/stdc++.h>
using namespace std;
int cmp(const void *a,const void *b)
{
    return *(int *)a<*(int *b);
}
typedef struct 
{
    int data;
    int order;
    int flag;
}A[200][200];

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int A[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> A[i][j].data;
            }
        }
        int B[m];
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {
                
            }
        }
    }
}