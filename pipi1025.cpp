#include<stdio.h>
int max = 100020;
int que[100020];
int book[100020];
int d[100020];//记录到根节点的距离 
int n,k;//n代表起点，k代表终点 
int bfs(){
	int i;
	for(i=0;i<max;i++){
		book[i]=0;
		d[i]=0; 
	}
	int head = 0;
	int tail = 0;
	que[tail++]=n;
	book[n]=1;
	while(head<tail){
		int  u = que[head++];
		if(u==k)
		return d[u];
		if(2*u>=1 && 2*u<max && book[2*u]==0){
			que[tail++]=2*u;
			book[2*u]=1;
			d[2*u] = d[u]+1;
		}
		if(1+u>=1 && 1+u<max && book[1+u]==0){
			que[tail++]=u+1;
			book[1+u]=1;
			d[1+u] = d[u]+1;
		}
		if(u-1>=0 && u-1<max && book[u-1]==0){
			que[tail++]=u-1;
			book[u-1]=1;
			d[u-1] = d[u]+1;
		}
	} 

	return -1; 

}
int main(){

	while(scanf("%d%d",&n,&k)!=EOF){

		printf("%d\n",bfs());

	}

}
