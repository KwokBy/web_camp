#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *fpWrite=fopen("SuperBig.txt","w");
    if(fpWrite==NULL)
    {
        return 0;
    }
    int k;
    printf("请输入你想要多少k的数据\n");
    scanf("%d",&k);
    for(long i=0;i<1000*k;i++)
        fprintf(fpWrite,"%d ",rand());
    fclose(fpWrite);
    printf("生成完毕，请在SuperBig.txt中查看\n");
    return 0;
}
