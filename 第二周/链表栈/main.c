#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\kwok\Desktop\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h"

int main(){
	LinkStack s;
	ElemType sizes;
	/*printf("������ջ�Ĵ�С\n");
	 while(1!=scanf("%d",&sizes)||sizes<0) //�ж��Ƿ�������Ч��  
     {printf("error,��������!\n");
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
	  		printf("��������1~6����Ч����\n");
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
				printf("������ջ��Աֵ\n");
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
		printf("���������?(1:yes/other num:no)");
	    n = inputerror();
	 }
	return 0;
}

