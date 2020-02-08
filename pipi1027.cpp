#include<bits/stdc++.h>
using namespace std;
int Getreal(string str)
{
    string Number[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    int i;
    for(i=0;i<10;i++)
    {
        if(str==Number[i])
        return i;
    }
}
int main()
{
    int a,b;
    string ca,cb;
    int i;
    while(true)
    {
        a=0;b=0;
        for(i=0;;i++)
        {
            cin>>ca;
            if(ca!="+")
            {
                if(i==1) a*=10;
                a+=Getreal(ca);
            }
            else
            {
                break;
            }
            
        }
        for(i=0;;i++)
        {
            cin>>cb;
            if(cb!="=")
            {
                if(i==1) b*=10;
                b+=Getreal(cb);
            }
            else
            {
                break;
            }
            
        }
        if(a+b==0) break;
        cout << a+b << endl;
    }
}