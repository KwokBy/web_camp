#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\kwok\Desktop\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h"

int main(){
	LinkStack s;
	ElemType sizes;
	/*printf("请输入栈的大小\n");
	 while(1!=scanf("%d",&sizes)||sizes<0) //判断是否输入有效数  
     {printf("error,重新输入!\n");
       while(getchar()!='\n'); 
     }*/
	initLStack(&s); 
	int length;
	ElemType data;
	ElemType data1;
	int val,n=1,flag=1;
     while(n==1){ 
     	system("cls");
		 show();
     	int j;
		val = inputerror(); 
	  while(val<0||val>6)
	  {
	  		printf("请输入在1~6的有效数字\n");
			  val = inputerror(); 
	  }
	  switch(val){
		case 1:
			{
				clearLStack(&s);
				break;
			}
		case 2:
			{
			   destroyLStack(&s);
			   break;
			}
		case 3:
			{
			   LStackLength(&s,&length);
			   break;	
			}
		case 4:
			{
				printf("请输入栈成员值\n");
	            data = inputerror();
				pushLStack(&s,data);
				break;
			}
		case 5:
			{
				popLStack(&s,&data1);
				printf("%d\n",data1);
				break;
			}
		case 6:
			exit(0);
		} 	
		printf("你想继续吗?(1:yes/other num:no)");
	    n = inputerror();
	 }
	return 0;
}

