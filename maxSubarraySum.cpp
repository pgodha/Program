#include<stdio.h>
void main()
{
     int arr[] ={1,2,3,-4,1,-3,4,5,-1,-2,8};
     int i,maxsum = 0;
     int curentsum = 0;
     int size,j;
     size = sizeof(arr)/sizeof(int);
     printf("%d", size);
     
     for(i = 0; i < size; i++ )
     {
             j = i; 
             currentsum = currentsum + arr[i];
             if(maxsum < currentsum)
                       maxsum = currentsum;
             if(maxsum <= 0)
             {
                    j = i   
                        
             }      
     }
     
     
     }
