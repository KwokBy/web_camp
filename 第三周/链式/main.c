#include"C:\Users\kwok\Desktop\QGѵ��Ӫ��������ѵ\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\ͷ�ļ�\LQueue.h"
#include<stdio.h>
#include<stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int val1;
int main(int argc, char *argv[]) {
	LQueue Q;
	 
	int seltion,n=1;
	void *pfun = *LPrint;
	printf("�����������������������(1.int\ 2.char)\n");
    scanf("%d",&val1);
	while(n==1){ 
     	system("cls");
	    show();
	  seltion = inputerror();
	  while(seltion>10||seltion<0){
	  	  printf("������1~10����Ч����\n");
		  seltion = inputerror();
	  }
	  switch(seltion){
		case 1:
			{
				InitLQueue(&Q); 
				printf("��ʼ���ɹ�\n");
				break;
			}
		case 2:
			{
			   DestoryLQueue(&Q);
			   break;
			}
		/*case 3:
			{
			   IsFullLQueue(&Q);
			   break;	
			}*/ 
		case 4:
			{
				IsEmptyLQueue(&Q);
				break;
			}
		case 5:
			{
				
				if(val1==1)
				{
				   int e;
				   GetHeadLQueue(&Q, &e);
				   printf("��ͷint��Ԫ��:%d\n",e);	
				}
				else if(val1==2)
				{
				   char e;
				   GetHeadLQueue(&Q, &e);
				   printf("��ͷchar��Ԫ��:%c\n",e);	
				}
				else if(val1==3)
				{
					double e;
					GetHeadLQueue(&Q, &e);
				    printf("��ͷdouble��Ԫ��:%lf\n",e);
				}
				break;
			}
		case 6:
			{
				printf("���г���Ϊ%d\n",LengthLQueue(&Q));
				break; 
			}
		case 7:
		    {
		    	printf("����������Ҫ�Ķ��г���\n");
		    	int size = inputerror();
		    	int i;
		    	for(i=0;i<size;i++)
		    	{
		    		
		    		if(val1==1)
		    		{
		    			int *data =(int *) malloc(sizeof(int));
		    			printf("������int��%d������\n",i+1);
		    			scanf("%d",data);
						EnLQueue(&Q, data);
					}
					else if(val1==2)
					{
					   char  *data = (char*)malloc(sizeof(char));
					   scanf("%c",data);
					   printf("������char�͵�%d������\n",i+1);
					   scanf("%c",data);
					   EnLQueue(&Q, data);	
					}
					else if(val1==3)
					{
					   double  *data = (double*)malloc(sizeof(double));
					   printf("������double�͵�%d������\n",i+1);
					   scanf("%f",data);
					   EnLQueue(&Q, data);
					   printf("double=====%lf\n",*data);	
					}
					
				}
				
		    	break;
			}		
		case 8:
			{
			    DeLQueue(&Q);
				break;	
			}
		case 9:
			{
				ClearLQueue(&Q);
				break;
			}
		case 10:
			{
				TraverseLQueue(&Q, pfun);
			}
		} 	
		printf("�㻹�������(1:yes/other num:no)");
		n = inputerror();
	}
}

