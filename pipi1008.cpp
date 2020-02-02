#include <stdio.h>   
#include <string.h>   
#include <ctype.h>   
#define N 202   
char str[N]={0}; 

int main(){
    gets(str);   
    while( strcmp(str, "ENDOFINPUT") != 0 )   //当没遇到消息集的结尾时
    { 
        if ( (strcmp(str, "START") !=0)&&(strcmp(str, "END") != 0) ) //当消息不是开始消息不是结尾
         {
            for(int i=0;i<strlen(str);i++)
            {
                if('A'<=str[i]&&str[i]<='E') str[i]+=21;
                else if('F'<=str[i]&&str[i]<='Z') str[i]-=5;
            }
            puts(str);
         }   
         gets(str);   //接受下一行
     } 
    return 0;   
}