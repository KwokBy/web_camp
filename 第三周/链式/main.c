#include"C:\Users\kwok\Desktop\QG训练营第三次培训\QG训练营第三次培训\代码和头文件\头文件\LQueue.h"
#include<stdio.h>
#include<stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int val1;
int main(int argc, char *argv[]) {
	LQueue Q;
	 
	int seltion,n=1;
	void *pfun = *LPrint;
	printf("请输入你想输入的数据类型(1.int\ 2.char)\n");
     val1 = inputerror();
	while(n==1){ 
     	system("cls");
	    show();
	  seltion = inputerror();
	  while(seltion>9||seltion<0){
	  	  printf("请输入1~9的有效数字\n");
		  seltion = inputerror();
	  }
	  switch(seltion){
		case 1:
			{
				InitLQueue(&Q); 
				break;
			}
		case 2:
			{
			   DestoryLQueue(&Q);
			   
			   break;
			}
		case 3:
			{
				IsEmptyLQueue(&Q);
				break;
			}
		case 4:
			{
				
					if(Q.length<0||Q.length>10)
               { 
    	         printf("请先初始化\n");
                break;
	           }
				if(val1==1)
				{
				   int e;
				   GetHeadLQueue(&Q, &e);
				   printf("队头int型元素:%d\n",e);
				   break;	
				}
				else if(val1==2)
				{
				   char e;
				   GetHeadLQueue(&Q, &e);
				   printf("队头char型元素:%c\n",e);
				   break;	
				}
			}
		case 5:
			{
					if(Q.length<0||Q.length>10)
               { 
    	         printf("请先初始化\n");
                break;
	           }
				printf("队列长度为%d\n",LengthLQueue(&Q));
				break; 
			}
		case 6:
		    {
		    	if(Q.length<0||Q.length>10)
               { 
    	         printf("请先初始化\n");
                break;
	           }
				printf("请输入你想要的队列长度\n");
		    	int size = inputerror();
		    	int i;
		    	for(i=0;i<size;i++)
		    	{
		    		
		    		if(val1==1)
		    		{
		    			int *data =(int *) malloc(sizeof(int));
		    			printf("请输入int型%d个数据\n",i+1);
		    			data = inputerror();
						EnLQueue(&Q, data);
					}
					else if(val1==2)
					{
					   char  *data = (char*)malloc(sizeof(char));
					   scanf("%c",data);
					   printf("请输入char型第%d个数据\n",i+1);
					   scanf("%c",data);
					   EnLQueue(&Q, data);	
					}
				}
				
		    	break;
			}		
		case 7:
			{
			    	if(Q.length<0||Q.length>10)
               { 
    	         printf("请先初始化\n");
                break;
	           }
			    DeLQueue(&Q);
				break;	
			}
		case 8:
			{
					if(Q.length<0||Q.length>10)
               { 
    	         printf("请先初始化\n");
                break;
	           }
				ClearLQueue(&Q);
				break;
			}
		case 9:
			{
					if(Q.length<0||Q.length>10)
               { 
    	         printf("请先初始化\n");
                break;
	           }
				TraverseLQueue(&Q, pfun);
			}
		} 	
		printf("你还想继续吗(1:yes/other num:no)");
		n = inputerror();
	}
}

