#include"C:\Users\kwok\Desktop\QG训练营第三次培训\QG训练营第三次培训\代码和头文件\头文件\LQueue.h"
#include<stdio.h>
#include<stdlib.h>


void InitLQueue(LQueue *Q)
{
      Q->front	= (Node*)malloc(sizeof(Node));
      if(!Q)
      {
      	return FALSE;
	  }
	  Q->rear = Q->front;
	  Q->front->next = NULL;
	  Q->length = 0; 
}
void DestoryLQueue(LQueue *Q)
{
    ClearLQueue(Q);
    free(Q->front);
    Q->front = NULL;
    Q->rear = NULL;
    Q->length = 0;
    Q=NULL;
	LQueue *p;
	
}
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length==0)
	{
		printf("队列为空\n");
		return TRUE;
	}
	return FALSE;
}
Status GetHeadLQueue(LQueue *Q, void *e)
{
   if(Q->length==0)
   {
   	return FALSE;
   }
   memcpy(e,Q->front->data,sizeof(*e));
   return TRUE;
}
int LengthLQueue(LQueue *Q)
{
   return	Q->length;
}
Status EnLQueue(LQueue *Q, void *data)
{
   LQueue * p = (Node*)malloc(sizeof(Node));
   Q->rear->data = data;
   Q->rear->next = p;
   Q->rear = p;
   Q->length++;
   //printf("in=======%d\n",*(int *)(Q->rear->data));
   return TRUE;	
}
Status DeLQueue(LQueue *Q)
{
   if(IsEmptyLQueue(Q))
   {
   	   printf("队列为空，无法出队\n");
	   return FALSE;
   }
  else
	  {
	  	Node *freeNode = Q->front;
        Q->front = Q->front->next;
        free(freeNode);
        Q->length--;
	    return TRUE;
	  }  
}
void ClearLQueue(LQueue *Q)
{
	while(Q->front==Q->rear)
	{
		Node * p = Q->front;
		Q->front =Q->front->next;
		free(p); 
	}
	Q->length=0;
}
Status TraverseLQueue(const LQueue *Q, void (*LPrint)(void *q))
{
	 if(Q->length==0)
   {
   	   printf("队列为空\n");
	   return FALSE;
   }
   Node *p = Q->front;
   while(p!=Q->rear)
   {
   	LPrint(p->data);
   	p= p->next;
   }
}
  
void LPrint(void *q)
{
	extern val1;
	if(val1==1)
	{
		printf("%d  ",*(int *)q);
	}
	if(val1==2)
	{
		printf("%c  ",*(char*)q);
	}
	if(val1==3)
	{
		printf("%lf  ",*(double*)q);
	}
}


void show(){
	printf(" ***************************************************************\n");
	printf(" *                                                             *\n");
	printf(" ***********************泛型链式队列****************************\n");
	printf(" *                                                             *\n");
	printf(" *************************选择菜单******************************\n");
	printf(" *                                                             *\n");
	printf(" *                         1、初始化队列                       *\n");
	printf(" *                         2、销毁队列                         *\n");
	printf(" *                         3、判断队列是否满                   *\n");
	printf("                           4、判断队列是否空                   *\n");
	printf(" *                         5、查看队头元素                     *\n");
	printf(" *                         6、 队列长度                        *\n");
	printf(" *                         7、 入队                            *\n");
	printf(" *                         8、 出队                            *\n");
	printf(" *                         9、 清空队列                        *\n");
	printf(" *                         10、 遍历队列                       *\n");
	printf(" *                                                             *\n");
	printf(" ***************************************************************\n");
	printf(" *                     请输入你想要进行的功能                  *\n");
	printf(" ***************************************************************\n");
}

int  inputerror(){
char a[20];
    scanf("%s",a);
    int val = 0;
    int i; 
    for( i=0;a[i];i++)
    {
        if((a[i]<'0'||a[i]>'9'))
        {
            memset(a,0,80);
            printf("非法输入，请重输\n");
            scanf("%s",a);
        }
    }
    for(i=0;a[i];i++){
        val = val*10+a[i]-'0';
    }
    return val;
}

