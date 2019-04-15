#include <stdio.h>
#include <stdlib.h>
#include<time.h>
    clock_t start,stop;
    double t;
int main()
{
     int val,n=1,flag=1;
     while(n==1){
     system("cls");
     show();
     int j;
     int a[200000]={0};
     int temp[200000]={0};
     val = inputerror();
     while(val>8||val<0){
	  	  printf("请输入在1~6的有效数字\n");
		  val = inputerror();
	  }
	  switch(val){

		case 1:
			{
                FILE *fp=fopen("SuperBig.txt","r");
				FILE *fp2=fopen("result1.txt","w");
				printf("你想要多长的数据\n");
				scanf("%d",&n);
				int i;
				for(i=0;i<n;i++)
				{
					fscanf(fp,"%d ",&a[i]);
				}
				start=clock();
				insertSort(a,n);
				stop=clock();
				t=(double)(stop-start)/CLK_TCK;
				printf("运行时间为:%f\n",t);
				int k=0;
				for(i=0;i<n;i++)
	            {
		          fprintf(fp2,"%d\t",a[i]);
		          k++;
		          if(k==10)
                  {
                      fprintf(fp2,"\n");
                      k=0;
                  }
	            }
	            fclose(fp2);
				fclose(fp);
				break;
			}
		case 2:
			{
			    FILE *fp=fopen("SuperBig.txt","r");
				FILE *fp2=fopen("result1.txt","w");
				printf("你想要多长的数据\n");
				scanf("%d",&n);
				int begin=0;
				int end=n-1;
				int i;
				for(i=0;i<n;i++)
				{
					fscanf(fp,"%d ",&a[i]);
				}
				start=clock();
				MergeSort(a,begin,end,temp);
				stop=clock();
				t=(double)(stop-start)/CLK_TCK;
				printf("运行时间为:%f\n",t);
				int k=0;
				for(i=0;i<n;i++)
	            {
		          fprintf(fp2,"%d\t",a[i]);
		          k++;
		          if(k==10)
                  {
                      fprintf(fp2,"\n");
                      k=0;
                  }
	            }
	            fclose(fp2);
				fclose(fp);
				break;
			}
		case 3:
			{
			    FILE *fp=fopen("SuperBig.txt","r");
				FILE *fp2=fopen("result1.txt","w");
				printf("你想要多长的数据\n");
				scanf("%d",&n);
				int begin=0;
				int end=n-1;
				int i;
				for(i=0;i<n;i++)
				{
					fscanf(fp,"%d ",&a[i]);
				}
				start=clock();
				QuickSort_Recursion(a,begin,end);
				stop=clock();
				t=(double)(stop-start)/CLK_TCK;
				printf("运行时间为:%f\n",t);
				int k=0;
				for(i=0;i<n;i++)
	            {
		          fprintf(fp2,"%d\t",a[i]);
		          k++;
		          if(k==10)
                  {
                      fprintf(fp2,"\n");
                      k=0;
                  }
	            }
	            fclose(fp2);
				fclose(fp);
				break;
			}
		case 4:
			{
			    FILE *fp=fopen("SuperBig.txt","r");
				FILE *fp2=fopen("result1.txt","w");
				printf("你想要多长的数据\n");
				scanf("%d",&n);
				int i;
				for(i=0;i<n;i++)
				{
					fscanf(fp,"%d ",&a[i]);
				}
				start=clock();
				QuickSort(a,n);
				stop=clock();
				t=(double)(stop-start)/CLK_TCK;
				printf("运行时间为:%f\n",t);
				int k=0;
				for(i=0;i<n;i++)
	            {
		          fprintf(fp2,"%d\t",a[i]);
		          k++;
		          if(k==10)
                  {
                      fprintf(fp2,"\n");
                      k=0;
                  }
	            }
	            fclose(fp2);
				fclose(fp);
				break;
			}
		case 5:
			{
			    FILE *fp=fopen("SuperBig.txt","r");
				FILE *fp2=fopen("result1.txt","w");
				printf("你想要多长的数据\n");
				scanf("%d",&n);
				int i;
				for(i=0;i<n;i++)
				{
					fscanf(fp,"%d ",&a[i]);
				}
				int max=a[0];
				for(i=1;i<n;i++)
				{
					max=max>a[i]?max:a[i];
				}
				start=clock();
				CountSort(a,n ,max);
				stop=clock();
				t=(double)(stop-start)/CLK_TCK;
				printf("运行时间为:%f\n",t);
				int k=0;
				for(i=0;i<n;i++)
	            {
		          fprintf(fp2,"%d\t",a[i]);
		          k++;
		          if(k==10)
                  {
                      fprintf(fp2,"\n");
                      k=0;
                  }
	            }
	            fclose(fp2);
				fclose(fp);
				break;
			}
		case 6:
			{
			    FILE *fp=fopen("SuperBig.txt","r");
				FILE *fp2=fopen("result1.txt","w");
				printf("你想要多长的数据\n");
				scanf("%d",&n);
				int i;
				for(i=0;i<n;i++)
				{
					fscanf(fp,"%d ",&a[i]);
				}
				start=clock();
				RadixCountSort(a,n);
				stop=clock();
				t=(double)(stop-start)/CLK_TCK;
				printf("运行时间为:%f\n",t);
				int k=0;
				for(i=0;i<n;i++)
	            {
		          fprintf(fp2,"%d\t",a[i]);
		          k++;
		          if(k==10)
                  {
                      fprintf(fp2,"\n");
                      k=0;
                  }
	            }
	            fclose(fp2);
				fclose(fp);
				break;
			}
        case 7:
            {
               FILE *fp=fopen("SuperBig.txt","r");
				FILE *fp2=fopen("result1.txt","w");
				printf("你想要多长的数据\n");
				scanf("%d",&n);
				int i;
				for(i=0;i<n;i++)
				{
					fscanf(fp,"%d ",&a[i]);
				}
				start=clock();
				ColorSort(a,n);
				stop=clock();
				t=(double)(stop-start)/CLK_TCK;
				printf("运行时间为:%f\n",t);
				int k=0;
				for(i=0;i<n;i++)
	            {
		          fprintf(fp2,"%d\t",a[i]);
		          k++;
		          if(k==10)
                  {
                      fprintf(fp2,"\n");
                      k=0;
                  }
	            }
	            fclose(fp2);
				fclose(fp);
				break;
            }
        case 8:
            {
               FILE *fp=fopen("SuperBig.txt","r");
				FILE *fp2=fopen("result1.txt","w");
				printf("你想要多长的数据\n");
				scanf("%d",&n);
				printf("你要第几大的数？\n");
				int k;
				scanf("%d",&k);
				int begin=0;
				int end=n-1;
				int i;
				for(i=0;i<n;i++)
				{
					fscanf(fp,"%d ",&a[i]);
				}
				start=clock();
				MergeSort(a,begin,end,temp);
				stop=clock();
				t=(double)(stop-start)/CLK_TCK;
				printf("运行时间为:%f\n",t);
                fprintf(fp2,"第k大为：%d\t",a[k]);
	            fclose(fp2);
				fclose(fp);
				break;
            }
		}
		printf("你想继续吗?(1:yes  other num:no)");
        n = inputerror();
	 }
	return 0;
}
