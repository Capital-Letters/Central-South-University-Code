#include<iostream>
#include<cmath>
using namespace std;
/*典型的动态规划题目，其实这道题可以拆开来看，行和列，先对每一行做动态规划，可以
得出这一行能够挖到的最大数量的金币，然后用一个数组把每一行的最大值记录下来，再
对这个数组进行动态规划，两次的规则是一样的*/
int distcol[205];//行记录
int distrol[205];//列记录
int result[205];//结果记录（到此行的最大金子数量）
int gold[205][205];
int max(int a, int b){
    if (a > b)return a;
    return b;
}
int main(){
    int n, m;
    while (cin>>n>>m){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> gold[i][j];
            }
        }
        for (int i = 0; i < n; i++){
            distcol[0] = gold[i][0];
            distcol[1] = max(gold[i][0], gold[i][1]);
            for (int j = 2; j < m; j++){//判断这个位置到底挖不挖
                distcol[j] = max(distcol[j - 1], distcol[j - 2] + gold[i][j]);
            }
            distrol[i] = distcol[m-1];
        }
        result[0] = distrol[0];
        result[1] = max(distrol[0], distrol[1]);
        for (int i = 2; i < n; i++){//判断这一行到底挖不挖
            result[i] = max(result[i - 1], result[i - 2] + distrol[i]);
        }
        cout << result[n - 1] << endl;

    }
    return 0;
}