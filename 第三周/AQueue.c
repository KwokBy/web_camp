#include"C:\Users\kwok\Desktop\QG训练营第三次培训\QG训练营第三次培训\代码和头文件\头文件\AQueue.h"
#include<stdio.h>
#include<stdlib.h>

void InitAQueue(AQueue *Q)
{
   Q = (AQueue*)malloc(MAXQUEUE*sizeof(AQueue));
   Q->front=0;
   Q->rear=0;
   Q->length=0;
}

void DestoryAQueue(AQueue *Q)
{
    free(Q);
    printf("销毁成功\n");
}

Status IsFullAQueue(const AQueue *Q)
{
	return (Q->rear+1)%MAXQUEUE == Q->front;
} 

Status IsEmptyAQueue(const AQueue *Q)
{
	return Q->front ==Q->rear;
}
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	e = Q->data;
	return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	Q->length = Q->rear -Q->front;
	return Q->length;
}
Status EnAQueue(AQueue *Q, void *data)
{
   if(IsFullAQueue(Q))
   {
   	    printf("队列满\n");
		return FALSE;
   }
   Q->rear = (Q->rear+1)%MAXQUEUE;
   Q->data[Q->rear] = data;
   Q->length++;
   printf("入队成功\n");
   printf("d======%d\n",*(int*)data);
   return TRUE;	
}
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("队列为空\n");
		return FALSE;
	}
	
	Q->front = (Q->front+1)%MAXQUEUE;
	printf("出队成功\n");
	return TRUE;
}
void ClearAQueue(AQueue *Q)
{
   Q->rear = Q->front;
   printf("清空成功\n"); 
}
Status TraverseAQueue(const AQueue *Q, void (*APrint)(void *q))
{
	if(Q->front==Q->rear)
	{
		return FALSE;
	}
	if(Q==NULL)
	{
		return FALSE;
	}
	int num = Q->front;
	while(num!=Q->rear)
	{
		APrint(Q->data[num]);
	     num = (num+1)%MAXQUEUE;
	}
	return TRUE;
}
void APrint(void *q)
{
	printf("请选择你要的数据类型\n");
	show(); 
	int sel;
	scanf("%d",&sel);
	if(sel==1)
	{
		printf("%d\n",*(int*)q);
	}
	if(sel==2)
	{
	   printf("%c\n",*(char*)q);	
	}
}

void show()
{
	printf("1、int\n");
	printf("2、char\n")	;		
}                    
