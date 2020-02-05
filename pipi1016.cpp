#include<bits/stdc++.h>
using namespace std;
int Isleap(int year)
{
    if(year%4==0&&year%100!=0||year%400==0) return 1;
    else return 0;
}
int dayofmonth[13][2]={
    0,0,
    31,31,
    28,29,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31,
    31,31,
    30,30,
    31,31,
    30,30,
    31,31
};
int main()
{
    int year,month,day;
    while(scanf("%d/%d/%d",&year,&month,&day)!=EOF)
    {
        int count=0;
        for(int i=0;i<month;i++)
        {
            count+=dayofmonth[i][Isleap(year)];
        }
        count+=day;
        cout << count << endl;
    }
}