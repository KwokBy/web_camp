#include<stdio.h>
#include<stdlib.h>
#include "C:\Users\kwok\Desktop\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h"
int main(){
	SqStack s;
	ElemType sizes;
	printf("������ջ�Ĵ�С\n");
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
	  	  printf("��������1~6����Ч����\n");
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
		         printf("ջ�������޷�������ջ\n");
		         printf("�������³�ʼ��ջ\n");
	           	 break;
				}
				printf("������ջ��Աֵ\n");
				/*while(1!=scanf("%d",&data)||n<0) //�ж��Ƿ�������Ч��  
                {printf("error,��������!\n");
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
		         printf("ջ�������޷�������ջ\n");
		         printf("�������³�ʼ��ջ\n");
	           	 break;
				}
				popStack(&s,&data1);
				printf("%d\n",data1);
				break;
			}
		case 6:
			{
				printf("������ջ�Ĵ�С\n");
	            sizes = inputerror();
             	initStack(&s,sizes); 
			}
		} 	
		printf("���������?(1:yes/other num:no)");
		/*while(1!=scanf("%d",&n)||n<0) //�ж��Ƿ�������Ч��  
     {printf("error,��������!\n");
       while(getchar()!='\n'); 
     }*/
       n = inputerror();
	 }
	return 0;
}

