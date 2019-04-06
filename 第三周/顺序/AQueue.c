#include"C:\Users\kwok\Desktop\QGѵ��Ӫ��������ѵ\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\ͷ�ļ�\AQueue.h"
#include<stdio.h>
#include<stdlib.h>

void InitAQueue(AQueue *Q)
{
   //Q = (AQueue*)malloc(MAXQUEUE*sizeof(AQueue));
   Q->front=0;
   Q->rear=0;
   Q->length=0;
}

void DestoryAQueue(AQueue *Q)
{
    if(Q->length<0||Q->length>10)
    {
    	printf("���ȳ�ʼ��������\n");
	}
	else
	{
       Q->length=-1;
       printf("���ٳɹ�\n");
    }
}

Status IsFullAQueue(const AQueue *Q)
{
   if((Q->rear+1)%MAXQUEUE == Q->front)
   {
   	   printf("������\n");
	   return TRUE;
   }
   return FALSE;
	
} 

Status IsEmptyAQueue(const AQueue *Q)
{
     if( Q->front==Q->rear)
     {
     	printf("����Ϊ��\n");
		 return TRUE;
	 }
	 return FALSE;
}
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(IsEmptyAQueue(Q))
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
	memcpy(e,Q->data+Q->front,sizeof(*e));
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
   if(Q->length<0||Q->length>10)
   {
   	printf("Ŀǰ����δ���ڣ����ȳ�ʼ��\n");
   	return FALSE;
   }
   memcpy(Q->data+Q->rear,data,sizeof(*data));
   Q->rear = (Q->rear+1)%MAXQUEUE;
   Q->length++;
   printf("��ӳɹ�\n");
   return TRUE;	
}
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("����Ϊ��\n");
		return FALSE;
	}
	if(Q->length<0||Q->length>10)
   {
   	printf("Ŀǰ����δ���ڣ����ȳ�ʼ��\n");
   }
	
	Q->front = (Q->front+1)%MAXQUEUE;
	Q->length--;
	//printf("fro======%d\n",Q->front);
	printf("���ӳɹ�\n");
	return TRUE;
}
void ClearAQueue(AQueue *Q)
{
   
   Q->rear = Q->front;
   Q->length=0;
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
		//printf("a====%d\n",*(int *)(Q->data[num]));
		//APrint(Q->data[num]); 
		APrint(Q->data+num);
	     num = (num+1)%MAXQUEUE;
	}
	return TRUE;
}
void APrint(void *q)
{
     int val1=1;
	 if(val1==1)
     {
     	printf("%d  ",*(int*)q);
     }
     else if(val1==2)
     {
     	printf("%c  ",*(char*)q);
	 }
}

void show(){
	printf(" ***************************************************************\n");
	printf(" *                                                             *\n");
	printf(" ***********************����˳�����****************************\n");
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
            printf("??????\n");
            scanf("%s",a);
        }
    }
    for(i=0;a[i];i++){
        val = val*10+a[i]-'0';
    }
    return val;
}


