
#include<stdio.h>

#include<math.h>

int main(){

	int n;

	int i=1;

	scanf("%d",&n);

	while(n--){

	double result=0;

	int x1,y1,x2,y2;

	int u1,v1,u2,v2;

	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);

	scanf("%d%d%d%d",&u1,&v1,&u2,&v2);

	double a,b;

	if((x1==x2)&&(y1==y2)){

		result=0;

	}

	else if((u1==u2)&&(v1==v2))

	result = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

	else{

	

	a=(u2-u1)*(u2-u1)+(v2-v1)*(v2-v1);

	b=2*(u2-u1)*(x2-x1)+2*(v2-v1)*(y2-y1);

	double zhong;

	zhong = -b/(2*a);

	if(zhong<0)

	zhong = 0;

 

	

	result = sqrt(((x2-x1)+(u2-u1)*zhong)*((x2-x1)+(u2-u1)*zhong)+((v2-v1)*zhong+(y2-y1))*((v2-v1)*zhong+(y2-y1))); 

}

	//result = (result*1000000+0.5)/1000000;

	printf("Case %d: %.6lf\n",i,result); 

	i++;

}

	

} 
