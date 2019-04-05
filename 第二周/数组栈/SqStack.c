#include "C:\Users\kwok\Desktop\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\SqStack.h"
#include<stdio.h>
#include<stdlib.h>
//˳��ջ(���������)
Status initStack(SqStack *s,int sizes)  //��ʼ��ջ
{
   s->elem = (ElemType*) malloc(sizes * sizeof(ElemType));
  if(!s->elem ){
   	return ERROR;
   }
   s->top = -1;
   s->size = sizes;
  // printf("caonima");
   return SUCCESS;
}
Status isEmptyStack(SqStack *s)   //�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==-1){
		printf("ջΪ��\n");
		return ERROR;
	}
	printf("ջ��Ϊ��\n");
	return SUCCESS;
} 
Status getTopStack(SqStack *s,ElemType *e)   //�õ�ջ��Ԫ��
{
	if(s->top==-1){
		printf("ջΪ��");
		return ERROR; 
	}
	printf("ջ��Ԫ��Ϊ��\t"); 
	*e = s->elem[s->top];
	return SUCCESS;
}
Status clearStack(SqStack *s)   //���ջ
{
	s->top = -1;	
}
Status destroyStack(SqStack *s)  //����ջ
{
  free(s->elem);
  s->elem = NULL;
  s->top = -1; 
  printf("���ٳɹ�\n");
  return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //���ջ
{
	*length = s->top+1;
	printf("ջ����Ϊ%d\n",*length);
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //��ջ
{
	if(s->elem ==NULL){
		printf("ջ�����ڣ��޷���ջ\n");
	}
	if(s->top>=s->size-1){
		printf("ջ�����޷���ջ��");
		return ERROR; 
	}
	s->elem[++(s->top)] = data;
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //��ջ
{
	if(&s==NULL){
		printf("ջ������\n");
		return ERROR;
	}
	if(s->top==-1){
	    printf("ջΪ�գ��޷���ջ��");
		return ERROR;	
	}
	*data = s->elem[s->top--]; 
	return SUCCESS;
}
//Ŀ¼ 
void show(){
	printf(" ***************************************************************\n");
	printf(" *                                                             *\n");
	printf(" ***********************���ݽṹ֮˳��ջ************************\n");
	printf(" *                                                             *\n");
	printf(" *************************���ߣ�������**************************\n");
	printf(" *                                                             *\n");
	printf(" *                         1�����ջ                           *\n");
	printf(" *                         2������ջ                           *\n");
	printf(" *                         3�����ջ��                         *\n");
	printf("                           4����ջ                             *\n");
	printf(" *                         5����ջ                             *\n");
	printf(" *                         6����ʼ��ջ                         *\n");
	printf(" *                                                             *\n");
	printf(" ***************************************************************\n");
	printf(" *                     ��������Ҫ���еĹ���                    *\n");
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
            printf("������\n");
            scanf("%s",a);
        }
    }
    for(i=0;a[i];i++){
        val = val*10+a[i]-'0';
    }
    return val;
}

