#include <bits/stdc++.h>
using namespace std;
typedef struct
{
    char name[9];
    int height;
}st;
int cmp(const void *a ,const void *b)
{
    st *c,*d;
    c=(st *)a;
    d=(st *)b;
    if(c->height!=d->height) return d->height-c->height;
    else
    {
        return strcmp(c->name,d->name);
    }
    
}
int main()
{
    int n,k,m,i;
    scanf("%d %d",&n,&k);
    st stu[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d",stu[i].name,&stu[i].height);
    }
    qsort(stu,n,sizeof(st),cmp);
    int t=0,row=k;
    while (row)
    {
        if(row==k) m=n/k+n%k;
        else m=n/k;
        char stemp[n][9];
        strcpy(stemp[m/2],stu[t].name);
        int j=m/2-1;
        for(i=t+1;i<t+m;i+=2)
        strcpy(stemp[j--],stu[i].name);
        j=m/2+1;
        for(i=t+2;i<t+m;i+=2)
        strcpy(stemp[j++],stu[i].name);
        printf("%s",stemp[0]);
        for(i=1;i<m;i++)
        printf(" %s",stemp[i]);
        printf("\n");
        row--;
        t+=m;
    }
    
}