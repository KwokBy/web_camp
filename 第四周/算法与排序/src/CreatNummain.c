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
    printf("����������Ҫ����k������\n");
    scanf("%d",&k);
    for(long i=0;i<1000*k;i++)
        fprintf(fpWrite,"%d ",rand());
    fclose(fpWrite);
    printf("������ϣ�����SuperBig.txt�в鿴\n");
    return 0;
}
