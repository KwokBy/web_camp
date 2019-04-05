#include<stdio.h>
#include "C:\Users\kwok\Desktop\计科3-郭国梁-作业类型（训练营、小组）-第一次\作业\代码和头文件\head\duLinkedlist.h"
#include<stdlib.h>
#include<string.h> 

int main(){
 
    DuLinkedList Head = (DuLinkedList)malloc(sizeof(DuLNode));
	InitList_DuL(&Head);
	//n用于记录用户的选择操作，j用于链表的遍历
	int n = 1, flag = 0, i;
	while (n == 1)
	{
		UserInterFace();
		if (flag == 0)
		{
			printf("链表目前为空, 你想生成链表吗(1：yes/other:no)");
			scanf("%d", &i);
			if(i==1)
			Append(&Head);
			else {
			 printf("\n没有生成链表不可以进行其他操作哦\n");
			 //printf("请重新输入\n");	
			  //printf("你想生成链表吗(1：yes/other:no)");
		     while(1!=scanf("%d",&i)||i<=0||i>=2) //判断是否输入有效数  
             {printf("error,重新输入!\n");
             //system("cls");
              printf("你想生成链表吗(1：yes/other:no)");
              while(getchar()!='\n'); 
             }
             if(i==1)
			Append(&Head);
			}
			flag = 1;
		}
		Select(&Head);
		printf("你想继续吗?(1:yes/other:no)");
		scanf("%d", &n);
		if(n == 1&&Head->next==NULL){
			flag = 0;
		}
	}

	return 0;
} 
