#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include "D:\calcul\finally.h"
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
    int k =0;
    while (str[i] != '\0' || EmptyStack(&opt) != OK)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
        
			tmp = tmp * 10 + str[i] - '0';
            i++;
            if(str[i]=='.')
			{
				while(str[i] < '0' || str[i] > '9')
				{
				  i++;
				  tmp = tmp*10+str[i]-'0';	
				  k++;
				}
			}
            if ((str[i] < '0' || str[i] >'9'))
            {
               //int x= 0;
			   //for(x=0;x<k;x++)
			    printf("kΪ%d\n",k);
			    tmp = tmp/pow(10,k);
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

