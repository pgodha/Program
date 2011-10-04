#include<stdio.h>
#include<conio.h>

int divide(int , int , int , int[]);
void swap(int, int,int[]);
int main()
{
    int arr[]={10,15,20,2,9,3,4,12,7,8};
    int pos;
    int pivot = 0;
    int left = 1;
    int len = sizeof(arr)/sizeof(arr[0]);
    int right = len - 1;
    int k = 3;
    int i = 0;
    while(i != 10)
    {
           // printf("%d",right);
            pos = divide(left, right, pivot,arr);
            printf("position %d", pos);
            if(k-1 == pos)
            {
                   printf("ans = %d", arr[k-1]);       
                   getch();
    return 0;
            }      
            else if ((k-1) < pos)
                   right = pos - 1;
            else 
                 {
                         left = pos + 1;
                         pivot = left;
                         }
             //    printf("%d",i);
                 i++;
    }
  
  //printf("hello"); 
  // System("PAUSE");
  getch();
    return 0;
}                  
       
    
    
    int divide(int left, int right, int pivot, int arr[])
    {
    //    printf("%d %d", left, right);
        while(left < right)
        {
                  
      //             printf("left= %d",left);
               while(arr[left] < arr[pivot])
               {
                               left++;
        //                       printf("inside");
                }
                while(arr[right] > arr[pivot])
                   right--;
               if(left < right)
               {
                       swap(left,right,arr);
                       left++;
                       right--;
                       }        
          //     printf("left is %d",arr[1]);                 
                
         }
                   swap(right,pivot,arr);
          return right;                

    }
    
    
    void swap(int x, int y, int arr[])
    {
            int temp;
            temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
            printf("hi"); 
    }
