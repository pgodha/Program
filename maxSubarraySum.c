#include<stdio.h>
int main()
{
     int arr[] ={1,2,3,-4,1,-3,4,5,-1,-2,8};
     int i,maxsum = 0;
     int currentsum = 0;
     int size,j=0,k,l;
     size = sizeof(arr)/sizeof(int);
     printf("%d", size);
     
     for(i = 0; i < size; i++ )
     { 
             currentsum = currentsum + arr[i];
             if(maxsum < currentsum)
             {
                       maxsum = currentsum;
                       l = i;
                       printf("maximum sum is %d \n ",maxsum);
             }
             if(currentsum <= 0)
             {
                    currentsum = 0;
                    j = i;   
                        
             }      
     }
     for(k = j ; k <=l ; k++)
           printf("%d \t",arr[k]);
           system("PAUSE");
     
   return 0;  
}
