
#include<stdio.h>
#include<malloc.h>

struct node
{
        int data;
        struct node* next;
};

void insert(int, struct node**);
struct node* create(int);
void delete(struct node**);
void reverse(struct node**);
void reverse_recurse(struct node**);
void display(struct node**);


int main()
{
        int choice,value;
        struct node* first = NULL;
        do
        {
                printf("Enter the operation you want to perform: \n 1.insert \n 2. delete \n 3. display \n 4.reverse \n 5.exit \n");
                scanf("%d",&choice );
                switch(choice)
                {
                        case 1: printf("\nEnter the value of node ");
                                scanf("%d",&value);
                                insert(value,&first);
                                printf("%d",first->data);break;
                        case 2: delete(&first);break;
                        case 3: display(&first);break;
                        case 4: reverse_recurse(&first);break;
                        case 5 : break;
                }
        }while(choice != 5);
        return 0;
}

struct node* create(int val)
{
        struct node* ptr = (struct node*)malloc(sizeof(struct node));
        ptr->data = val;
        ptr->next = NULL;
        return ptr;
}


void insert(int value, struct node** first)
{
        struct node* temp;
        struct node* ptr = create(value);
        if(*first == NULL)
                *first = ptr;
        else
        {
                temp = *first;
                while(temp->next != NULL)
                        temp = temp->next;

                temp->next = ptr;
        }
    
}

void delete(struct node** first)
{
        struct node* temp1;
        struct node* temp2;
        if(*first == NULL)
        {
                  printf("Link list is empty");
                  return;
                  }
        if((*first)->next == NULL)
                *first = NULL;        
        else
        {
                printf("printed"); 
                temp1 = *first;
                temp2 = temp1->next;
                while(temp2->next != NULL)
                {
                        temp2 = temp2->next;
                        temp1 = temp1->next;
                }
                temp1->next = NULL;
                free(temp2);
        }
        
}

void  display(struct node** first)
{
      if(first == NULL)
               printf("Linklist is empty");
        struct node* temp = *first;
        while(temp != NULL)
        {
                printf("%d \t", temp->data);
                temp = temp->next;
        }
         
}                                                                                                                                                                 

void reverse( struct node** first)
{
     struct node* ptr = *first;
     struct node* temp = ptr->next;
     struct node* ptr1 = temp->next;
     (*first)->next = NULL;
     while(1)
     {
           printf("\n %d \n ",ptr->data);
           temp->next = ptr;
           if(ptr1 == NULL)
           {
                 *first = temp;
                  break;
           }          
           ptr = temp;
           temp = ptr1;
           ptr1 = ptr1->next;
     }

}     
     
void reverse_recurse(struct node** temp)
{
     struct node* first;
     if((*temp)->next != NULL)
     {
           reverse_recurse(&((*temp)->next));
           printf("%d \n",(*temp)->data);
           (*temp)->next->next = *temp;
     }
     else
         first = *temp; 
     
}    
     
    
