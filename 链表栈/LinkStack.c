#include<stdio.h>
#include<stdlib.h>
#include"C:\Users\kwok\Desktop\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\LinkStack.h"

//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	s->top = (LinkStackPtr)malloc(sizeof(StackNode));
	s->top = NULL;
	s->count = 0; 
} 
Status isEmptyLStack(LinkStack *s)  //判断链栈是否为空
{
    return (s->top==NULL);
} 
Status getTopLStack(LinkStack *s,ElemType *e)  //得到栈顶元素
{
	if(s->count==-1){
		printf("栈为空\n");
		return ERROR;
	}
	*e = s->top->data;
	return SUCCESS; 
}
Status clearLStack(LinkStack *s)   //清空栈
{
	if(s->top==NULL){
		printf("栈已为空，不用进行清空\n");
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
  printf("清空成功\n");
  s->top = NULL;
  s->count = 0; 
  return SUCCESS;
}
Status destroyLStack(LinkStack *s)   //销毁栈
{
	//clearLStack(s);
	/*free(s);
	printf("销毁成功\n");
	s->count = -1;
	return SUCCESS;*/
	if(s->top==NULL){
		printf("无法销毁\n");
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
Status LStackLength(LinkStack *s,int *length)    //检测栈长度
{
  *length = s->count;	
  printf("栈长度为%d\n",*length);
}
Status pushLStack(LinkStack *s,ElemType data)   //入栈
{
	LinkStackPtr p;
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
	
}
Status popLStack(LinkStack *s,ElemType *data)   //出栈
{
	if(s->top==NULL){
		printf("栈为空\n");
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
            printf("请重输\n");
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
	printf(" ***********************数据结构之顺序栈************************\n");
	printf(" *                                                             *\n");
	printf(" *************************作者：郭国梁**************************\n");
	printf(" *                                                             *\n");
	printf(" *                         1、清空栈                           *\n");
	printf(" *                         2、销毁栈                           *\n");
	printf(" *                         3、检查栈长                         *\n");
	printf("                           4、入栈                             *\n");
	printf(" *                         5、出栈                             *\n");
	printf(" *                         6、退出                             *\n");
	printf(" *                                                             *\n");
	printf(" ***************************************************************\n");
	printf(" *                     请输入你要进行的功能                    *\n");
	printf(" ***************************************************************\n");
}
