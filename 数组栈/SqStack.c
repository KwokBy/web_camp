#include "C:\Users\kwok\Desktop\QG训练营第二次培训\栈以及栈的应用\栈\代码和头文件\head\SqStack.h"
#include<stdio.h>
#include<stdlib.h>
//顺序栈(基于数组的)
Status initStack(SqStack *s,int sizes)  //初始化栈
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
Status isEmptyStack(SqStack *s)   //判断栈是否为空
{
	if(s->top==-1){
		printf("栈为空\n");
		return ERROR;
	}
	printf("栈不为空\n");
	return SUCCESS;
} 
Status getTopStack(SqStack *s,ElemType *e)   //得到栈顶元素
{
	if(s->top==-1){
		printf("栈为空");
		return ERROR; 
	}
	printf("栈顶元素为：\t"); 
	*e = s->elem[s->top];
	return SUCCESS;
}
Status clearStack(SqStack *s)   //清空栈
{
	s->top = -1;	
}
Status destroyStack(SqStack *s)  //销毁栈
{
  free(s->elem);
  s->elem = NULL;
  s->top = -1; 
  printf("销毁成功\n");
  return SUCCESS;
}
Status stackLength(SqStack *s,int *length)   //检测栈
{
	*length = s->top+1;
	printf("栈长度为%d\n",*length);
	return SUCCESS;
}
Status pushStack(SqStack *s,ElemType data)  //入栈
{
	if(s->elem ==NULL){
		printf("栈不存在，无法出栈\n");
	}
	if(s->top>=s->size-1){
		printf("栈满，无法入栈。");
		return ERROR; 
	}
	s->elem[++(s->top)] = data;
	return SUCCESS;
}
Status popStack(SqStack *s,ElemType *data)   //出栈
{
	if(&s==NULL){
		printf("栈不存在\n");
		return ERROR;
	}
	if(s->top==-1){
	    printf("栈为空，无法出栈。");
		return ERROR;	
	}
	*data = s->elem[s->top--]; 
	return SUCCESS;
}
//目录 
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
	printf(" *                         6、初始化栈                         *\n");
	printf(" *                                                             *\n");
	printf(" ***************************************************************\n");
	printf(" *                     请输入你要进行的功能                    *\n");
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
            printf("请重输\n");
            scanf("%s",a);
        }
    }
    for(i=0;a[i];i++){
        val = val*10+a[i]-'0';
    }
    return val;
}

