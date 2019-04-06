#include"C:\Users\kwok\Desktop\QG训练营第三次培训\QG训练营第三次培训\代码和头文件\头文件\AQueue.h"
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
    	printf("请先初始化在销毁\n");
	}
	else
	{
       Q->length=-1;
       printf("销毁成功\n");
    }
}

Status IsFullAQueue(const AQueue *Q)
{
   if((Q->rear+1)%MAXQUEUE == Q->front)
   {
   	   printf("队列满\n");
	   return TRUE;
   }
   return FALSE;
	
} 

Status IsEmptyAQueue(const AQueue *Q)
{
     if( Q->front==Q->rear)
     {
     	printf("队列为空\n");
		 return TRUE;
	 }
	 return FALSE;
}
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(IsEmptyAQueue(Q))
	{
		printf("队列为空\n");
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
   	    printf("队列满\n");
		return FALSE;
   }
   if(Q->length<0||Q->length>10)
   {
   	printf("目前队列未存在，请先初始化\n");
   	return FALSE;
   }
   memcpy(Q->data+Q->rear,data,sizeof(*data));
   Q->rear = (Q->rear+1)%MAXQUEUE;
   Q->length++;
   printf("入队成功\n");
   return TRUE;	
}
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q))
	{
		printf("队列为空\n");
		return FALSE;
	}
	if(Q->length<0||Q->length>10)
   {
   	printf("目前队列未存在，请先初始化\n");
   }
	
	Q->front = (Q->front+1)%MAXQUEUE;
	Q->length--;
	//printf("fro======%d\n",Q->front);
	printf("出队成功\n");
	return TRUE;
}
void ClearAQueue(AQueue *Q)
{
   
   Q->rear = Q->front;
   Q->length=0;
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
	printf(" ***********************泛型顺序队列****************************\n");
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
            printf("??????\n");
            scanf("%s",a);
        }
    }
    for(i=0;a[i];i++){
        val = val*10+a[i]-'0';
    }
    return val;
}


