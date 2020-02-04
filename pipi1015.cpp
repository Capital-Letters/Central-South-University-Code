#include<bits/stdc++.h>
using namespace std;

struct node{
    double z,h;
}a[100+10];

int cmp(const node &a,const node &b){
    return a.z<b.z;
}

int main()
{
    int n,t;
    while(scanf("%d %d",&n,&t)!=EOF){
        for(int i=0;i<n;i++)
        {
            scanf("%lf %lf",&a[i].z,&a[i].h);
        }
        sort(a,a+n,cmp);
        double ans = 0.0;
        for(int i=0;i<n;i++)
        {
            if(t>=a[i].h){
                t=t-a[i].h;
                ans+=a[i].z * a[i].h;
            }else{
                ans+=a[i].z * t;
                t=0.0;
                break;
            }
        }
        printf("%d\n",(int)ans+t);
    }
    return 0;

}

