#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "C:\Users\kwok\learngit\第二周\计算器\finally.h"
int main()
{
    char str[100] = {0};
    int i = 0; 
	double j;
    double tmp = 0;
    Stack num, opt;

    if (InitStack(&num) != OK || InitStack(&opt) != OK)
    {
        printf("Init Failure!\n");
        exit(1);
    }

    printf("Please input operator :\n");
    scanf("%s",&str);
    double k =0;
    while (str[i] != '\0' || EmptyStack(&opt) != OK)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
        
			tmp = tmp * 10 + str[i] - '0';
            i++;
            if(str[i]=='.')
			{
				i++;
				while(str[i] >= '0' && str[i] <= '9')
				{
				  
				  if (str[i] >= '0' && str[i] <= '9') {
				  	tmp = tmp*10+str[i]-'0';	
				  }
				  i++;	
				  k++;
				}
			}
            if ((str[i] < '0' || str[i] >'9'))
            {
               
			    printf("k为%f\n",k);
			    printf("k is  p=====  %f\n",pow(10,k));
			    printf("sda  %f\n",tmp);
			    tmp = tmp/pow(10,k);
				printf("dsf %f\n",tmp) ;
                k = 0;
				Push(&num, tmp);
                tmp = 0;
            }
        }

        else
        {
            if (EmptyStack(&opt) == OK || (GetTop(&opt) == '(' && str[i] != ')') ||
                Priority(str[i]) > Priority(GetTop(&opt)))
            {
                Push(&opt, str[i]);
                i++;
                continue;
            }

            if (GetTop(&opt) == '(' && str[i] == ')')
            {
                Pop(&opt);
                i++;
                continue;
            }

            if ((str[i] == '\0' && EmptyStack(&opt) != OK) || str[i] == ')' && GetTop(&opt) != '(' ||
                Priority(str[i]) <= Priority(GetTop(&opt)))
            {
                switch((int)Pop(&opt))
                {
                    case '+':
                        Push(&num, Pop(&num) + Pop(&num));
                        break;
                    case '-':
                        j = Pop(&num);
                        Push(&num, Pop(&num) - j);
                        break;
                    case '*':
                        Push(&num, Pop(&num) * Pop(&num));
                        break;
                    case '/':
                        j = Pop(&num);
                        Push(&num, Pop(&num) / j);
                        break;
                }

                continue;
            }
        }
    }

    printf("%f\n",Pop(&num));
    return 0;
}

