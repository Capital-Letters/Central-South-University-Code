#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        int x,y;
        int cost=0;
        int posx[n],posy[n];
        for(int i=0;i<n;i++)
        {
            cin >> posx[i] >> posy[i]; 
        }
        sort(posx,posx+n);
        sort(posy,posy+n);
        for(int i=0;i<n;i++)
        {
            posx[i]-=i;
        }
        sort(posx,posx+n);
        int mx=posx[n/2];
        int my=posy[n/2];
        for(int i=0;i<n;i++)
        {
            cost+=abs(posx[i]-mx);
            cost+=abs(posy[i]-my);
        }
        cout << cost << endl;
    }
}