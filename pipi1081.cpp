#include<bits/stdc++.h>
using namespace std;
int bisearch(int B[],int left,int right,int num)
{
    int mid;
    if(B[right]<=num) return right+1;
    while(left<right)
    {
        mid=left+(right-left)/2;
        if(B[mid]<=num) left=mid+1;
        else right=mid;
    }
    return left;

}
int main()
{
    int n;
    while(cin>>n)
    {
        int A[n];
        for(int i=0;i<n;i++) cin >>A[i];
        int B[n+1];
        B[1]=A[0];
        int len=1;
        for(int i=1;i<n;i++)
        {
            int next=bisearch(B,1,len,A[i]);
            B[next]=A[i];
            if(next>len) len=next;
        }
        cout << len << endl;
    }
}