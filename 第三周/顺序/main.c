#include <stdio.h>
#include <stdlib.h>
#include"C:\Users\kwok\Desktop\QGѵ��Ӫ��������ѵ\QGѵ��Ӫ��������ѵ\�����ͷ�ļ�\ͷ�ļ�\AQueue.h" 
int val1;
int main(int argc, char *argv[]) {
	AQueue Q;
	
	int seltion,n=1;
	void *pfun = *APrint;
	printf("����������Ҫ������(1��int\ 2��char)\n");
    val1 = inputerror();
    while(val1!=1&&val1!=2)
    {
    	printf("������1��int 2��char\n");
    	val1 = inputerror();
	}
	while(n==1){ 
     	system("cls");
	    show();
	  seltion = inputerror();
	  while(seltion>10||seltion<0){
	  	  printf("�Ƿ����룬������1~10������\n");
		  seltion = inputerror();
	  }
	  switch(seltion){
		case 1:
			{
				if(Q.length>=0&&Q.length<=10)
                {           
    	           printf("�����Զ�γ�ʼ��Ŷ\n");
    	           break;
	            }
				InitAQueue(&Q); 
				printf("��ʼ���ɹ�\n");
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
                    	printf("Ŀǰ����δ���ڣ����ȳ�ʼ��\n");
   	                    break;
                    }
				//printf("sizeof======%d\n",sizeof(Q.data));
				if(val1==1)
				{
				   int e;
				   GetHeadAQueue(&Q, &e);
				   printf("��ͷԪ��Ϊint�͵�:%d\n",e);	
				}
				else if(val1==2)
				{
				   char e;
				   GetHeadAQueue(&Q, &e);
				   printf("��ͷԪ��Ϊint�͵�:%c\n",e);	
				}
				break;
			}
		case 6:
			{
				printf("���г���Ϊ��%d\n",LengthAQueue(&Q));
				break; 
			}
		case 7:
		    {
		    	if(Q.length<0||Q.length>10)
                 {
   	                printf("Ŀǰ����δ���ڣ����ȳ�ʼ��\n");
   	                break;
                 }
				printf("��������Ҫ��ӵĸ��������10����\n");
		    	int size = inputerror();
		    	int i;
		    	
		    	for(i=0;i<size;i++)
		    	{
		    		
		    		if(val1==1)
		    		{
		    			int data;
		    			printf("������int�͵�%d����\n",i+1);
		    			data = inputerror();
						EnAQueue(&Q, &data);
					}
					else if(val1==2)
					{
					   char  data;
					   scanf("%c",&data);
					   printf("������char�͵�%d����\n",i+1);
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
                    	printf("Ŀǰ����δ���ڣ����ȳ�ʼ��\n");
   	                    break;
                    }
	
				DeAQueue(&Q);
				break;	
			}
		case 9:
			{
					if(Q.length<0||Q.length>10)
                    {
                    	printf("Ŀǰ����δ���ڣ����ȳ�ʼ��\n");
   	                    break;
                    }
				ClearAQueue(&Q);
				break;
			}
		case 10:
			{
					if(Q.length<0||Q.length>10)
                    {
                    	printf("Ŀǰ����δ���ڣ����ȳ�ʼ��\n");
   	                    break;
                    }
				TraverseAQueue(&Q, pfun);
			}
		} 	
		printf("����Ҫ������(1:yes/other num:no)");
		n = inputerror();
	}
}
