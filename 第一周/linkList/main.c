#include "../head/linkedList.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
	LinkedList Head = (LinkedList)malloc(sizeof(LNode));
	InitList(&Head);
	//n���ڼ�¼�û���ѡ�������j��������ı���
	int n = 1,flag = 0,i;
	while (n==1)
	{
		
		if (flag == 0)
		{
			UserInterFace();
			printf("����ĿǰΪ��, ��������������(1��yes/other:no)");
			scanf("%d", &i)
			if(i==1)
			Append(&Head);
			else {
			 printf("\nû�������������Խ�����������Ŷ\n");
			 //printf("����������\n");	
			  //printf("��������������(1��yes/other:no)");
		     while(1!=scanf("%d",&i)||i<=0||i>=2) //�ж��Ƿ�������Ч��  
             {printf("error,��������!\n");
             //system("cls");
              printf("��������������(1��yes/other:no)");
              while(getchar()!='\n'); 
             } 
             if(i==1)
			Append(&Head);
			} 
			flag = 1;
		}
		Select(&Head);
		printf("���������?(1:yes/other:no)");
		scanf("%d", &n);
		char c;
		while ((c = getchar()) != '\n');
		if(n == 1&&Head->next==NULL){
			flag = 0;
		}
		else exit(0);
 }
	system("pause");
	return 0;
}
