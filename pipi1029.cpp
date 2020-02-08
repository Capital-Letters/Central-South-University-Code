#include<bits/stdc++.h>
using namespace std;
typedef struct {
    long long int price;
    long long int volume;
    double single_price;
}kele;
int cmp(const void *a,const void *b)
{
    kele *c,*d;
    c=(kele *)a;
    d=(kele *)b;
    return c->single_price>d->single_price;
}
int main()
{
    int n;
    long long int L;
    while (cin>>n>>L)
    {
        kele k[n];
        for(int i=0;i<n;i++)
        {
            cin>>k[i].price;
            k[i].volume=1<<i;
            k[i].single_price=(double)k[i].price/k[i].volume;
        }
        qsort(k,n,sizeof(kele),cmp);
        long long int quantity;
        long long int sum=0;
        long long int min;
        for(int i=0;i<n;i++)
        {
            // cout << k[i].single_price << endl;
            int cost=k[i].price;
            int vol=k[i].volume;
            sum+=(L/vol)*cost;
            if(i==0) min=cost+(L/vol)*cost;
            if(L%vol==0)
            {
                if(sum<min) min=sum; 
                break;
            }
            if(sum+cost<min)
            {
                min=sum+cost;
            }
            L%=vol;
            // cout << quantity << " " << L << " " << sum << endl;
            
        }
        cout << min << endl;
    }
    
}