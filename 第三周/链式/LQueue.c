#include"C:\Users\kwok\Desktop\QGѵ��Ӫ��������ѵ\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\ͷ�ļ�\LQueue.h"
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
		printf("����Ϊ��\n");
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
   	   printf("����Ϊ�գ��޷�����\n");
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
   	   printf("����Ϊ��\n");
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
	printf(" ***********************������ʽ����****************************\n");
	printf(" *                                                             *\n");
	printf(" *************************ѡ��˵�******************************\n");
	printf(" *                                                             *\n");
	printf(" *                         1����ʼ������                       *\n");
	printf(" *                         2�����ٶ���                         *\n");
	printf(" *                         3���ж϶����Ƿ���                   *\n");
	printf("                           4���ж϶����Ƿ��                   *\n");
	printf(" *                         5���鿴��ͷԪ��                     *\n");
	printf(" *                         6�� ���г���                        *\n");
	printf(" *                         7�� ���                            *\n");
	printf(" *                         8�� ����                            *\n");
	printf(" *                         9�� ��ն���                        *\n");
	printf(" *                         10�� ��������                       *\n");
	printf(" *                                                             *\n");
	printf(" ***************************************************************\n");
	printf(" *                     ����������Ҫ���еĹ���                  *\n");
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
            printf("�Ƿ����룬������\n");
            scanf("%s",a);
        }
    }
    for(i=0;a[i];i++){
        val = val*10+a[i]-'0';
    }
    return val;
}

