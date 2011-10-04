#include<stdio.h>

int main()
{
    int num = 5;
    int temp = 0x1000;
    int result;
    
    result = 5&temp;
    
    printf("result: %d",result);
    system("PAUSE");
    return 0;    
}
