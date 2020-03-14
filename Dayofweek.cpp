#include<cstdio>
#include<cstring>
int isyeap(int x)
{
    if(x%4==0&&x%100!=0||x%400==0) 
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
int dayofMonth[13][2] = {
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
int buf[3001][13][32]; //表示第i年第j月第k天距离0-1-1的天数
struct Data
{
    int year;
    int month;
    int day;
    void nextDay()
    {
        day++;
        if (day>dayofMonth[month][isyeap(year)])
        {
            day=1;
            month++;
            if(month>12)
            {
                month=1;
                year++;
            }
        }
    }
};
int main()
{
    
}