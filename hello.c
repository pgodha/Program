
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
void display(struct node**);


void main()
{
        int choice,value;
        struct node* first = NULL;
        do
        {
                printf("Enter the operation you want to perform: \n 1.insert \n 2. delete \n 3. display \n 4.exit \n");
                scanf("%d",&choice );
                switch(choice)
                {
                        case 1: printf("\nEnter the value of node ");
                                scanf("%d",&value);
                                insert(value,&first);
                                printf("%d",first->data);break;
                        case 2: delete(&first);break;
                        case 3: display(&first);break;
                        case 4 : break;
                }
        }while(choice != 4);

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
                printf("Link list is empty");
        else
        {
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

void display(struct node** first)
{
        struct node* temp = *first;
        while(temp != NULL)
        {
                printf("%d \t", temp->data);
                temp = temp->next;
        }
}






                                                                                                                                                                             97,1-8        Bot
