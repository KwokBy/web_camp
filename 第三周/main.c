#include <stdio.h>
#include <stdlib.h>
#include"C:\Users\kwok\Desktop\QG训练营第三次培训\QG训练营第三次培训\代码和头文件\头文件\AQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	AQueue Q;
	InitAQueue(&Q);
	int data= 6;
	int e;
	EnAQueue(&Q, &data);
	IsFullAQueue(&Q);
	GetHeadAQueue(&Q, &e);
	void * pfun;
	pfun = &APrint;
	TraverseAQueue(&Q, pfun);
	return 0;
}
