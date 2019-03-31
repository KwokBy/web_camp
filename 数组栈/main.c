#include<stdio.h>
#include<stdlib.h>
#include "C:\Users\kwok\Desktop\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h"
int main(){
	SqStack s;
	ElemType sizes;
	printf("请输入栈的大小\n");
    sizes = inputerror();
	initStack(&s,sizes);  
	int length;
	ElemType data;
	ElemType data1;
	int val,n=1,flag=1;
     while(n==1){ 
     	system("cls");
		 show();
     	int j;
	  val = inputerror();
	  while(val>6||val<0){
	  	  printf("请输入在1~6的有效数字\n");
		  val = inputerror();
	  }
	  switch(val){
		case 1:
			{
				clearStack(&s);
				break;
			}
		case 2:
			{
			   destroyStack(&s);
			   break;
			}
		case 3:
			{
			   stackLength(&s,&length);
			   break;	
			}
		case 4:
			{
				if(s.elem==NULL){
		         printf("栈已销毁无法进行入栈\n");
		         printf("请再重新初始化栈\n");
	           	 break;
				}
				printf("请输入栈成员值\n");
				/*while(1!=scanf("%d",&data)||n<0) //判断是否输入有效数  
                {printf("error,重新输入!\n");
                 while(getchar()!='\n'); 
                }*/
                data = inputerror();
	            //scanf("%d",&data);
				pushStack(&s,data);
				break;
			}
		case 5:
			{
				if(s.elem==NULL){
		         printf("栈已销毁无法进行入栈\n");
		         printf("请再重新初始化栈\n");
	           	 break;
				}
				popStack(&s,&data1);
				printf("%d\n",data1);
				break;
			}
		case 6:
			{
				printf("请输入栈的大小\n");
	            sizes = inputerror();
             	initStack(&s,sizes); 
			}
		} 	
		printf("你想继续吗?(1:yes/other num:no)");
		/*while(1!=scanf("%d",&n)||n<0) //判断是否输入有效数  
     {printf("error,重新输入!\n");
       while(getchar()!='\n'); 
     }*/
       n = inputerror();
	 }
	return 0;
}

