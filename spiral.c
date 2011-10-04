#include<stdio.h>
void lefttobottom(int[][],int,int,int,int);
void righttotop(int[][],int,int,int,int);
int main()
{

    int i,j;
    int arr[][4]={{1,2,3,4},
                 {5,6,7,8},
                 {9,10,11,12}};         
    lefttobottom(arr,0,0,2,3);

    
        system("PAUSE");             
    return 0;    
}

void lefttobottom(int arr[][4],int x1, int y1, int x2, int y2)
{
     int i,j;
     for(i = y1; i <=y2; i++)
            printf("%d\t",arr[x1][i]);
     for(j = x1+1; j<=x2; j++)           
            printf("%d\t",arr[j][y2]);

     if(x2-x1 >0 && y2-y1 > 0)            
     righttotop(arr,x2,y2-1,x1+1,y1);       
}

void righttotop(int arr[][4],int x1, int y1, int x2, int y2)
{
     int i,j;
     for(i = y1; i >=y2; i--)
            printf("%d\t",arr[x1][i]);
     for(j = x1-1; j>=x2; j--)           
            printf("%d\t",arr[j][y2]);
    if(x1-x2 >0 && y1-y2 > 0)                 
     lefttobottom(arr,x2,y2+1,x1-1,y1);       
     
}
