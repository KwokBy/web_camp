#include <stdio.h>
#include <stdlib.h>
#include<time.h>
    clock_t start,stop;
    double duration;
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ��������
 *  @param       : ����ָ�� a, ���鳤�� n
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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
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
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
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
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size)
{
   int p_stack[size];
 	int top=0;
 	int high=size-1,low=0;
 	int midd=Partition(a,low,high);
 	//��ջ
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
	//��ջ
	while(top>0)
	{
		high=p_stack[--top];
		low=p_stack[--top];
		midd=Partition(a,low,high);
		//����ջ
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
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
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
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size)
 {

	int i;
 	int exc=1;        //��ÿ��λ����
 	int max=a[0];     //��maxֵ
 	for(i=1;i<size;i++)
 	{
 		max=max>a[i]?max:a[i];  //�����ֵ
	 }
	while(max/exc){    //ÿһλѭ��ʹ�� ���������������
    int rtips[10]={0};
 	int rsorted[size];
 	for(i=0;i<size;i++)  //0-9������ͳ��
 	{
		rtips[a[i]/exc%10]++;
	 }
	for(i=1;i<10;i++)    //��ǰ���ȫ��ͳ��
	{
		rtips[i]+=rtips[i-1];
	}
	for(i=size;i>0;i--)    //ʹ�ø��������������
	{
		rsorted[rtips[a[i-1]/exc%10]-1]=a[i-1];
		rtips[a[i-1]/exc%10]--;
	}
	for(i=0;i<size;i++)   //���������鸳ֵ��a����
	{
		a[i]=rsorted[i];
	}
	exc*=10;
 }
 }

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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
 *  @description : ҳ��˵�
 */

void show(){
	printf(" ***************************************************************\n");
	printf(" *                                                             *\n");
	printf(" *************************�㷨���������************************\n");
	printf(" *                                                             *\n");
	printf(" ****************************ѡ��˵�***************************\n");
	printf(" *                                                             *\n");
	printf(" *                         1����������                         *\n");
	printf(" *                         2���鲢����                         *\n");
	printf(" *                         3����������(�ݹ�)                   *\n");
	printf("                           4����������(�ǵݹ�)                 *\n");
	printf(" *                         5����������                         *\n");
	printf(" *                         6����������                         *\n");
	printf(" *                         7����ɫ����                         *\n");
	printf(" *                         8��Ѱ�ҵ�k��                        *\n");
	printf(" *                                                             *\n");
	printf(" ***************************************************************\n");
	printf(" *                       ��ѡ������Ҫ�Ĺ���                    *\n");
	printf(" ***************************************************************\n");
}


/**
 *  @name        : int  inputerror()
 *  @description : ���Ƿ�����
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
            printf("����Ƿ���������\n");
            scanf("%s",a);
        }
    }
    for(i=0;a[i];i++){
        val = val*10+a[i]-'0';
    }
    return val;
}

 /*void WriteSort(int x){
    printf("����Ҫ���ٸ�����\n");
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
    printf("����ʱ��%f\n",duration);
    printf("��������Ѵ���result2.txt�ĵ�����ǰ���鿴\n");
   return 0;
}*/
