#include<stdio.h>
#include "C:\Users\kwok\Desktop\�ƿ�3-������-��ҵ���ͣ�ѵ��Ӫ��С�飩-��һ��\��ҵ\�����ͷ�ļ�\head\duLinkedlist.h"
#include<stdlib.h>
#include<string.h> 

int main(){
 
    DuLinkedList Head = (DuLinkedList)malloc(sizeof(DuLNode));
	InitList_DuL(&Head);
	//n���ڼ�¼�û���ѡ�������j��������ı���
	int n = 1, flag = 0, i;
	while (n == 1)
	{
		UserInterFace();
		if (flag == 0)
		{
			printf("����ĿǰΪ��, ��������������(1��yes/other:no)");
			scanf("%d", &i);
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
		if(n == 1&&Head->next==NULL){
			flag = 0;
		}
	}

	return 0;
} 
