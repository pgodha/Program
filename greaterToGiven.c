#include<stdio.h>
#include<math.h>

int getLength(int);
int extractDigit(int,int);

int main()
{
    int num = 1234;
    int digit1,digit2,length;
    int i,j,k,flag,tempnumb,tempnumb1,final;
    int tempsum = 0;
    length = getLength(num);
 //printf("length : %d\n", length);
   
   for (i = 1 ; i < length ; i++ )
   {
       for (j = 0 ; j < i ; j++)
       {
           if(extractDigit(i,num) < extractDigit(j,num))
           {
                                  printf("hi");
              //      temp = i+1;
                    tempnumb = num/pow(10,(length-i-1));
                    tempnumb1 = extractDigit(j,num)*pow(10,i);            
                    for(k = 0 ; k < i ; k++)
                    {
                            tempsum = tempsum + extractDigit(k,num)*pow(10,i);
                    }       
                    
                    final = tempnumb1 + tempsum;
                    printf("%d\n",final);
                    flag = 1;
                    break;
           }
       }
       if(flag = 1)
               break;
   }                      
   
   
   
   
   
   /* while(i < length)   
   {
           if( extractDigit(num,i) > extractDigit(num,i+1) )             
               (num/pow(10,i+2))*pow(10,i+2) + extractDigit(num,i+1)*pow(10,i+2) + extractDigit(num,i)*pow(10,i+1)
            printf("%d ------------ %d\n",digit1,digit2);
            i++;
    }*/
   // check(1)
    system("PAUSE");
    return 0;
}

int extractDigit(int num,int pos)
{
    int msb,value;
    msb = num/(pow(10,pos));
   // printf("\n%d",msb);
    value = msb%10;
    return value;
}

int getLength(int number)
{
    int i = 0;
    int itr = 1;
    while (itr != 0)
    {
          i++;
          itr = number/(pow(10,i));
    }      
    return i;
}
