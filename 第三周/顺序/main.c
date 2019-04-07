#include <stdio.h>
#include <stdlib.h>
#include"C:\Users\kwok\Desktop\QG训练营第三次培训\QG训练营第三次培训\代码和头文件\头文件\AQueue.h" 
int val1;
int main(int argc, char *argv[]) {
	AQueue Q;
	
	int seltion,n=1;
	void *pfun = *APrint;
	printf("请输入你想要的类型(1、int\ 2、char)\n");
    val1 = inputerror();
    while(val1!=1&&val1!=2)
    {
    	printf("请重输1、int 2、char\n");
    	val1 = inputerror();
	}
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
				if(Q.length>=0&&Q.length<=10)
                {           
    	           printf("不可以多次初始化哦\n");
    	           break;
	            }
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
				
					if(Q.length<0||Q.length>10)
                    {
                    	printf("目前队列未存在，请先初始化\n");
   	                    break;
                    }
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
				break;
			}
		case 6:
			{
				printf("队列长度为：%d\n",LengthAQueue(&Q));
				break; 
			}
		case 7:
		    {
		    	if(Q.length<0||Q.length>10)
                 {
   	                printf("目前队列未存在，请先初始化\n");
   	                break;
                 }
				printf("请输入想要入队的个数（最多10个）\n");
		    	int size = inputerror();
		    	int i;
		    	
		    	for(i=0;i<size;i++)
		    	{
		    		
		    		if(val1==1)
		    		{
		    			int data;
		    			printf("请输入int型第%d数据\n",i+1);
		    			data = inputerror();
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
				}
				
		    	break;
			}		
		case 8:
			{
			    	if(Q.length<0||Q.length>10)
                    {
                    	printf("目前队列未存在，请先初始化\n");
   	                    break;
                    }
	
				DeAQueue(&Q);
				break;	
			}
		case 9:
			{
					if(Q.length<0||Q.length>10)
                    {
                    	printf("目前队列未存在，请先初始化\n");
   	                    break;
                    }
				ClearAQueue(&Q);
				break;
			}
		case 10:
			{
					if(Q.length<0||Q.length>10)
                    {
                    	printf("目前队列未存在，请先初始化\n");
   	                    break;
                    }
				TraverseAQueue(&Q, pfun);
			}
		} 	
		printf("你想要继续吗(1:yes/other num:no)");
		n = inputerror();
	}
}
