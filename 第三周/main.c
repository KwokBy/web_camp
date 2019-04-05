#include <stdio.h>
#include <stdlib.h>
#include"C:\Users\kwok\Desktop\QG训练营第三次培训\QG训练营第三次培训\代码和头文件\头文件\AQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {
	AQueue Q;
	 int val1;
	int seltion,n=1;
	void *pfun = *APrint;
	printf("请输入你想要的类型(1、int\ 2、char)\n");
    scanf("%d",&val1);
	while(n==1){ 
     	system("cls");
	    show();
	  seltion = inputerror();
	  while(seltion>10||seltion<0){
	  	  printf("非法输入，请输入1~10的数字\n");
		  seltion = inputerror();
	  }
	  switch(seltion){
		case 1:
			{
				InitAQueue(&Q); 
				printf("初始化成功\n");
				break;
			}
		case 2:
			{
			   DestoryAQueue(&Q);
			   break;
			}
		case 3:
			{
			   IsFullAQueue(&Q);
			   break;	
			}
		case 4:
			{
				IsEmptyAQueue(&Q);
				break;
			}
		case 5:
			{
				
				//printf("sizeof======%d\n",sizeof(Q.data));
				if(val1==1)
				{
				   int e;
				   GetHeadAQueue(&Q, &e);
				   printf("队头元素为int型的:%d\n",e);	
				}
				else if(val1==2)
				{
				   char e;
				   GetHeadAQueue(&Q, &e);
				   printf("队头元素为int型的:%c\n",e);	
				}
				else if(val1==3)
				{
					double e;
					GetHeadAQueue(&Q, &e);
				    printf("队头元素为int型的:%f\n",e);
				}
				break;
			}
		case 6:
			{
				printf("队列长度为：%d\n",LengthAQueue(&Q));
				break; 
			}
		case 7:
		    {
		    	printf("请输入想要入队的个数（最多10个）\n");
		    	int size = inputerror();
		    	int i;
		    	
		    	for(i=0;i<size;i++)
		    	{
		    		
		    		if(val1==1)
		    		{
		    			int data;
		    			printf("请输入int型第%d数据\n",i+1);
		    			scanf("%d",&data);
						EnAQueue(&Q, &data);
					}
					else if(val1==2)
					{
					   char  data;
					   scanf("%c",&data);
					   printf("请输入char型第%d数据\n",i+1);
					   scanf("%c",&data);
					   EnAQueue(&Q, &data);	
					}
					else if(val1==3)
					{
					   char  data;
					   scanf("%f",&data);
					   printf("请输入char型第%d数据\n",i+1);
					   scanf("%f",&data);
					   EnAQueue(&Q, &data);	
					}
					
				}
				
		    	break;
			}		
		case 8:
			{
			    DeAQueue(&Q);
				break;	
			}
		case 9:
			{
				ClearAQueue(&Q);
				break;
			}
		case 10:
			{
				TraverseAQueue(&Q, pfun);
			}
		} 	
		printf("你想要继续吗(1:yes/other num:no)");
		n = inputerror();
	}
}
