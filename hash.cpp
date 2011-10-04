#include<stdio.h>
#include<conio.h>
#include<malloc.h>
void put(int , int);
int get(int);
struct linklist
{
       int Key;
       int Value;
       struct linklist* link;
};
struct linklist* arr[10] = {NULL};
int main()
{
    int key;
    int value;
    int keysearch,valuesearch;
    while(1)
    {
    printf("Enter key:");
    scanf("%d",&key);
    printf("If you are enough put value equal to -1 else Enter value:");
    scanf("%d",&value);
    if(value == -1)
    break;
    put(key,value);
    
    }
    printf("Enter Key to serach");
    scanf("%d",&keysearch);
    valuesearch = get(keysearch);
    if(valuesearch == -1)
                   printf("not found");
    else
        printf("value found -> %d",valuesearch);
        getch();
        return 0;
}
void put(int key, int value)
{
     struct linklist* node;
     int index;
     index = key%10;
     node = (struct linklist*)malloc(sizeof(struct linklist));
     node->Key = key;
     node->Value = value;
     if(arr[index] == NULL)
     {
     arr[index] = node;
     arr[index]->link = NULL;  
     }
     else
     {
         node->link = arr[index];         
         arr[index] = node;
     }
}     

int get(int key)
{
    int index = key%10;
    struct linklist* node;
    if(arr[index] == NULL)
    {
                  printf("not found");
                return -1;
    }
    //else if(arr[index]->link == NULL)
      //   return arr[index]->Value;
    else
    {
        node = arr[index];
        while(1)
        {
            if(node->Key == key)
                         return node->Value;
            node = node->link;
        }
        printf("not found");
        return -1;     
    }            
}
