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
     val1 = inputerror();
	while(n==1){ 
     	system("cls");
	    show();
	  seltion = inputerror();
	  while(seltion>9||seltion<0){
	  	  printf("������1~9����Ч����\n");
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
    	         printf("���ȳ�ʼ��\n");
                break;
	           }
				if(val1==1)
				{
				   int e;
				   GetHeadLQueue(&Q, &e);
				   printf("��ͷint��Ԫ��:%d\n",e);
				   break;	
				}
				else if(val1==2)
				{
				   char e;
				   GetHeadLQueue(&Q, &e);
				   printf("��ͷchar��Ԫ��:%c\n",e);
				   break;	
				}
			}
		case 5:
			{
					if(Q.length<0||Q.length>10)
               { 
    	         printf("���ȳ�ʼ��\n");
                break;
	           }
				printf("���г���Ϊ%d\n",LengthLQueue(&Q));
				break; 
			}
		case 6:
		    {
		    	if(Q.length<0||Q.length>10)
               { 
    	         printf("���ȳ�ʼ��\n");
                break;
	           }
				printf("����������Ҫ�Ķ��г���\n");
		    	int size = inputerror();
		    	int i;
		    	for(i=0;i<size;i++)
		    	{
		    		
		    		if(val1==1)
		    		{
		    			int *data =(int *) malloc(sizeof(int));
		    			printf("������int��%d������\n",i+1);
		    			data = inputerror();
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
				}
				
		    	break;
			}		
		case 7:
			{
			    	if(Q.length<0||Q.length>10)
               { 
    	         printf("���ȳ�ʼ��\n");
                break;
	           }
			    DeLQueue(&Q);
				break;	
			}
		case 8:
			{
					if(Q.length<0||Q.length>10)
               { 
    	         printf("���ȳ�ʼ��\n");
                break;
	           }
				ClearLQueue(&Q);
				break;
			}
		case 9:
			{
					if(Q.length<0||Q.length>10)
               { 
    	         printf("���ȳ�ʼ��\n");
                break;
	           }
				TraverseLQueue(&Q, pfun);
			}
		} 	
		printf("�㻹�������(1:yes/other num:no)");
		n = inputerror();
	}
}

