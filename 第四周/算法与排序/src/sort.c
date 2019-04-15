#include <stdio.h>
#include <stdlib.h>
#include<time.h>
    clock_t start,stop;
    double duration;
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
    int i = 0;
    for(i = 1;i < n;i++)
    {
        int temp = *(a+i);
        int j = 0;
        for(j = i - 1;j >= 0 && *(a+j) > temp;j--)
        {
            *(a+j + 1) = *(a+j);
        }
        *(a+j + 1) = temp;

    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int i=begin;
    int j=mid+1;
    int t=0;
    while(i<=mid&&j<=end){
        if(a[i]<a[j]){
            temp[t++]=a[i++];
        }else{
          temp[t++]=a[j++];
        }
    }
    while(i<=mid){
        temp[t++]=a[i++];
    }
    while(j<=end){
        temp[t++]=a[j++];
    }
    t=0;
    while(begin<=end){
        a[begin++]=temp[t++];
    }
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
   if(begin<end){
    int mid=(begin+end)/2;
    MergeSort(a,begin,mid,temp);
    MergeSort(a,mid+1,end,temp);
    MergeArray(a,begin,mid,end,temp);
   }
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
    int temp;
    int t;
    if(begin>end){
        return;
    }
    temp=*(a+begin);
    int i=begin;
    int j=end;
    while(i!=j){
        while(*(a+j)>=temp&&i<j){
            j--;
        }
        while (*(a+i)<=temp&&i<j){
            i++;
        }
        if(i<j){
            t=*(a+i);
            *(a+i)=*(a+j);
            *(a+j)=t;
        }
    }
    *(a+begin) = *(a+i);
    *(a+i) = temp;
    QuickSort_Recursion(a, begin, i-1);
    QuickSort_Recursion(a, i+1, end);
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size)
{
   int p_stack[size];
 	int top=0;
 	int high=size-1,low=0;
 	int midd=Partition(a,low,high);
 	//入栈
	if(midd>low+1)
	{
		p_stack[top++]=low;
		p_stack[top++]=midd-1;

	 }
	if(midd<high-1)
	{
		p_stack[top++]=midd+1;

		p_stack[top++]=high;
	}
	//出栈
	while(top>0)
	{
		high=p_stack[--top];
		low=p_stack[--top];
		midd=Partition(a,low,high);
		//再入栈
		if(midd>low+1)
		{
			p_stack[top++]=low;
		    p_stack[top++]=midd-1;
		}
		if(midd<high-1)
		{
			p_stack[top++]=midd+1;
		    p_stack[top++]=high;
		}
	 }

}

/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
   int left=begin,right=end;
 	int temp=a[left];
 	while(right>left){
 		while(right>left&&a[right]>=temp){
 			right--;
		 }
		 if(right>left)a[left]=a[right];
		while(right>left&&a[left]<=temp){
			left++;
		}
		if(right>left)a[right]=a[left];
	 }
	a[left]=temp;

	return left;

}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
    int b[size];
    int c[max+1];
    memset(c, 0, (max+1)*sizeof(int));
    for(int i=0;i<size;i++)
      c[*(a+i)]++;
    for (int i = 1; i < max + 1; i++)
     {
         c[i] = c[i] + c[i - 1];
     }
     for (int i = 0; i < size; i++)
     {
         c[*(a+i)]--;
         b[c[*(a+i)]] = *(a+i);
     }
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size)
 {

	int i;
 	int exc=1;        //求每个位的数
 	int max=a[0];     //存max值
 	for(i=1;i<size;i++)
 	{
 		max=max>a[i]?max:a[i];  //求最大值
	 }
	while(max/exc){    //每一位循环使用 计数排序进行排序
    int rtips[10]={0};
 	int rsorted[size];
 	for(i=0;i<size;i++)  //0-9个数的统计
 	{
		rtips[a[i]/exc%10]++;
	 }
	for(i=1;i<10;i++)    //从前向后全部统计
	{
		rtips[i]+=rtips[i-1];
	}
	for(i=size;i>0;i--)    //使用辅助数组进行排序
	{
		rsorted[rtips[a[i-1]/exc%10]-1]=a[i-1];
		rtips[a[i-1]/exc%10]--;
	}
	for(i=0;i<size;i++)   //将辅助数组赋值给a数组
	{
		a[i]=rsorted[i];
	}
	exc*=10;
 }
 }

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size){
	int *p,*p0,*p2;
	p0 = a;
	p = a + 1;
	p2 = a + size - 1;
	int i = 0;
	while(p != p2){
		if(*p == 0){
			int temp = *p;
			*p = *p0;
			*p0 = temp;
			p0++;
		}
		if(*p == 2){
			int temp = *p;
			*p = *p2;
			*p2 = temp;
			p2--;
		}
		if(*p == 1)
		p++;
  }
    if(*p == 0){
			int temp = *p;
			*p = *p0;
			*p0 = temp;
			p0++;
		}
		if(*p == 2){
			int temp = *p;
			*p = *p2;
			*p2 = temp;
			p2--;
		}
}

/**
 *  @name        : void show()
 *  @description : 页面菜单
 */

void show(){
	printf(" ***************************************************************\n");
	printf(" *                                                             *\n");
	printf(" *************************算法与排序测试************************\n");
	printf(" *                                                             *\n");
	printf(" ****************************选择菜单***************************\n");
	printf(" *                                                             *\n");
	printf(" *                         1、插入排序                         *\n");
	printf(" *                         2、归并排序                         *\n");
	printf(" *                         3、快速排序(递归)                   *\n");
	printf("                           4、快速排序(非递归)                 *\n");
	printf(" *                         5、计数排序                         *\n");
	printf(" *                         6、基数排序                         *\n");
	printf(" *                         7、颜色排序                         *\n");
	printf(" *                         8、寻找第k大                        *\n");
	printf(" *                                                             *\n");
	printf(" ***************************************************************\n");
	printf(" *                       请选择你想要的功能                    *\n");
	printf(" ***************************************************************\n");
}


/**
 *  @name        : int  inputerror()
 *  @description : 检测非法输入
 */

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
            printf("输入非法，请重输\n");
            scanf("%s",a);
        }
    }
    for(i=0;a[i];i++){
        val = val*10+a[i]-'0';
    }
    return val;
}

 /*void WriteSort(int x){
    printf("你需要多少个数据\n");
        int size;
        scanf("%f",&size);
    int i = 0;
    int len;
    int temp;
    int a[size];
    int b[size];
    int begin=0;
    int end=size-1;
    int max=32759;
    start=clock();
    FILE *fp;
    fp = fopen("SuperBig.txt","r");
    if(fp == NULL)
    {
        perror("fopen");
    exit(1);
    }

    while(!feof(fp))
    {
        fscanf(fp,"%d",&temp);
    a[i] = temp;
    i++;
    }
    fclose(fp);
    switch(x)
    {
       case 1:
           {
              insertSort(a,i);
              break;
           }
       case 2:
        {
                long size;
        scanf("%d",&size);
    int i = 0;
    int len;
    int temp;
    int a[size];
    int b[size];
    int begin=0;
    int end=size-1;
    int max=32759;
            MergeSort(a,begin,end,b);
            break;
        }
       case 3:
        {
            QuickSort_Recursion(a,begin,end);
            break;
        }
       case 4:
        {
            QuickSort(a,size);
            break;
        }
       case 5:
        {
             CountSort(a,size,32759);
             break;
        }
       case 6:
        {
            RadixCountSort(a,size);
            break;
        }
       case 7:
        {
            ColorSort(a,size);
            break;
        }
    }
    /*sort(a,i-1);
    MergeSort(a,0,199999,b);
    insertSort(a,i);
    QuickSort_Recursion(a,0,199999);
    CountSort(a, 199999, 32767 );
    len = i-1;

    fp = fopen("result2.txt","w+");
    if(fp == NULL)
    {
        perror("fopen2:");
    exit(1);
    }
    int k=0;
    for(i = 0; i < len; i++)
    {
        fprintf(fp,"%d  ",a[i]);
        k++;
        if(k==10){
          fprintf(fp,"\n");
          k=0;
        }
    }
    fclose(fp);
    stop=clock();
    duration=((double)(stop-start)/CLK_TCK);
    printf("排序时间%f\n",duration);
    printf("排序后结果已存入result2.txt文档，请前往查看\n");
   return 0;
}*/
