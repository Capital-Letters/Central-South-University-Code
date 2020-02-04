
#include<iostream>

#include<algorithm>

#define LL long long

using namespace std;

int main()

{

    LL n,x,y;

    LL ans;

    while(scanf("%lld",&n)!=EOF)

    {

        ans = 0;

        x = n/4;

        y = n%4;

        if(y<2)

        	ans = 4*x*x;

        else

        	ans = 4*x*(x+1);
        if(y==1)

        	ans+=2*x-1;

        else if(y==3)

        	ans+=2*x+1;

        	

        if(ans&1)

        	printf("%lld.5\n",ans/2);

        else

        	printf("%lld.0\n",ans/2);

    }

    return 0;

}
