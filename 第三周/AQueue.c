#include"C:\Users\kwok\Desktop\QGѵ��Ӫ��������ѵ\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\ͷ�ļ�\AQueue.h"
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
    printf("���ٳɹ�\n");
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
   	    printf("������\n");
		return FALSE;
   }
   Q->rear = (Q->rear+1)%MAXQUEUE;
   Q->data[Q->rear] = data;
   Q->length++;
   printf("��ӳɹ�\n");
   printf("d======%d\n",*(int*)data);
   return TRUE;	
}
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
	
	Q->front = (Q->front+1)%MAXQUEUE;
	printf("���ӳɹ�\n");
	return TRUE;
}
void ClearAQueue(AQueue *Q)
{
   Q->rear = Q->front;
   printf("��ճɹ�\n"); 
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
	printf("��ѡ����Ҫ����������\n");
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
	printf("1��int\n");
	printf("2��char\n")	;		
}                    
