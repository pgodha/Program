#include<stdio.h>

int main()
{
    int value = 4;
    int temp = 0x80000000;
    int result,flag = 0;;
    int num,i = 0;
    num = value;
    result = num&temp;
    while(result == 0)
    {
          num = num<<1;
          result = num&temp;
          i++;
    }       
    
    while(i<32)
    {
       flag = 0;
       if( result != 0)
       {
               if((value&1) != 1)
               {
                          flag = 1;
                          break;
               }
       }
       else
       {
           if((value&1) != 0)
           {
                   flag = 1;
                    break;
           }
       }
       i++;
       num = num<<1;
       result = num&temp;
       value = value>>1;
       
    }   
    
    if( flag == 0)
        printf("yes Palindrome");
    else
        printf("No it's not palindrome");
      
    system("PAUSE");
    return 0;    
}
