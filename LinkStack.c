#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\kwok\Desktop\QGѵ��Ӫ�ڶ�����ѵ\ջ�Լ�ջ��Ӧ��\ջ\�����ͷ�ļ�\head\LinkStack.h"

//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	s->top = NULL;
	s->count = 0; 
} 
Status isEmptyLStack(LinkStack *s)  //�ж���ջ�Ƿ�Ϊ��
{
    return (s->top==NULL);
} 
Status getTopLStack(LinkStack *s,ElemType *e)  //�õ�ջ��Ԫ��
{
	if(s->count==-1){
		printf("ջΪ��\n");
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS; 
}
Status clearLStack(LinkStack *s)   //���ջ
{
	if(s->top==NULL){
		printf("ջ��Ϊ�գ����ý������\n");
		return ERROR;
	}
	LinkStackPtr p;
	LinkStackPtr q;
	p=s->top;
	while(p){
	q = p->next;
	free(p); 
	p = q;
  }
  printf("��ճɹ�\n");
  s->top = NULL;
  s->count = 0; 
  return SUCCESS;
}
Status destroyLStack(LinkStack *s)   //����ջ
{
	//clearLStack(s);
	/*free(s);
	printf("���ٳɹ�\n");
	s->count = -1;
	return SUCCESS;*/
	if(s->top==NULL){
		printf("�޷�����\n");
		return ERROR;
	}
	LinkStackPtr p;
	while(p!=NULL){
	p = s->top;
	s->top = p->next;
	//s->count--;
	free(p);
	s->count = 0;
	return ERROR;
 }
 //free(s->top);
 s->count = 0;
 s->top = NULL;
 return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)    //���ջ����
{
  *length = s->count;	
  printf("ջ����Ϊ%d\n",*length);
}
Status pushLStack(LinkStack *s,ElemType data)   //��ջ
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
	
}
Status popLStack(LinkStack *s,ElemType *data)   //��ջ
{
	if(s->top==NULL){
		printf("ջΪ��\n");
		return ERROR;
	}
	*data = s->top->data;
	LinkStackPtr p;
	p = s->top;
	s->top = p->next;
	s->count--;
	free(p);
	return SUCCESS;
}
int  inputerror(){
char a[80];
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
	printf(" *                         6���˳�                             *\n");
	printf(" *                                                             *\n");
	printf(" ***************************************************************\n");
	printf(" *                     ��������Ҫ���еĹ���                    *\n");
	printf(" ***************************************************************\n");
}
