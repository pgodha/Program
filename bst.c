#include<stdio.h>
#include<malloc.h>



typedef struct btree 
{
    struct btree* left;
    struct btree* right;
    int data;
}node;
void insert(int, node** );
void display(node**);
void delete(node**, int);
int height(node*);
int max(int, int);
int sumNode(node*);
int isSumTree(node*);


int main()
{
       int choice,value,depth,n;
        node* root;
        root = NULL;
        do
        {
                printf("Enter the operation you want to perform: \n 1.Insert \n 2.Delete \n 3.Height \n 4.Display \n 5.SumNode \n 6.MaxHeight\n 7.isSumTree\n 8.Exit \n");
                scanf("%d",&choice );
                switch(choice)
                {
                        case 1: printf("\nEnter the value of node ");
                                scanf("%d",&value);
                                insert(value,&root);
                                break;
                        case 2: printf("Enter the value of node you want to delete");
                                scanf("%d", &value);
                                delete(&root,value);break;
                        case 3: depth = height(root);
                                printf("%d",depth);break;        
                        case 4: display(&root);break;
                        case 5: sumNode(root);break;
                        case 6 : printf("Max height: %d\n",maxHeight(root));
                              break;
                              
                        case 7:isSumTree(root);
                             break;
                        case 8:break;     
                }
        }while(choice != 8);
        return 0;   
    
    
    }

node* create(int val)
{
        node* ptr = (node*)malloc(sizeof(node));
        ptr->data = val;
        ptr->left = NULL;
        ptr->right = NULL;
        return ptr;
}

void insert(int val, node** root)
{
     node* ptr;
     node* ptr1;
     node* temp = create(val);
     if(*root == NULL)
             *root = temp;
     else
     {
         printf("hi\n");
         ptr = *root;
         while(ptr  != NULL)
         {
             ptr1 = ptr;
             if(val <= ptr->data)
                 ptr = ptr->left;
             else
                 ptr = ptr->right;
         }
         if(val < ptr1->data)
                ptr1->left = temp;
         else
             ptr1->right = temp;
         
     }
}

void delete(node** root, int value)
{
     node* ptr1;
     node* temp = *root;
     node* ptr = temp;
     while(temp != NULL)
     {
        if(value == temp->data)
                 break;
        else if(value < temp->data)
        {
             ptr = temp;
             temp = temp->left;
        }
        else
        {
             ptr = temp;
             temp = temp->right;
        }
     }    
     
     if(temp->left == NULL && temp->right == NULL)
     {
              if(value < ptr->data)
                       ptr->left = NULL;
              else 
                       ptr->right = NULL;
     }                
     else if(temp->left != NULL && temp->right == NULL)
     {
          if(value < ptr->data)
                   ptr->left = temp->left;
          else 
                    ptr->right = temp->left;
          
     }  
     else if(temp->left == NULL && temp->right != NULL)
     {
          if(value < ptr->data)
                   ptr->left = temp->right;
          else 
                   ptr->right = temp->right;
          
     }          
     else
     {
         ptr1 = temp;
         ptr1 = ptr1->right;
         if(ptr1->left == NULL)
         {
                       temp->data = (temp->right)->data;
                      temp->right = NULL;
                      return;
         }            
         while(ptr1->left->left!= NULL)
                      ptr1 = ptr1->left;
         temp->data = (ptr1->left)->data;
         ptr1->left = NULL;
         
     }
}

int height(node* temp)
{
    int h1=0;
    int h2=0;
    if(temp == NULL)
            return 0;
    if(temp->left != NULL)
         h1 = height(temp->left);
    if(temp->right != NULL)
         h2 = height(temp->right);                  
    return (max(h1,h2)+1);
}

int max(int x, int y)
{   int max;
    if(x>y)
      return x;
      else 
      return y;
}



void display(node** root)
{
     node* temp = *root;
     if(temp != NULL)
     {
           display(&(temp->left));
           printf("%d \t",temp->data);
           display(&(temp->right));     
     }
}

int sumNode(node* temp)
{
     if(temp != NULL)
     {
             if(temp->left == NULL && temp->right == NULL)
              {    return temp->data;     }
              else
              {   return temp->data=(sumNode(temp->left) + sumNode(temp->right));  }
      }
      else 
       { return 0;}
}      

int maxHeight(node* current)
{
    if(NULL == current)
    {return 0;}
    else
    {
        int rh=maxHeight(current->right);
        int lh=maxHeight(current->left);
        return (rh>=lh?rh:lh)+1;
    }
}
/*  Pranay code for node sum         
int sumNode(node* temp)
{
     if(temp != NULL)
     {
             if(temp->left != NULL && temp->right != NULL)
                           return temp->data=(sumNode(temp->left) + sumNode(temp->right));
             else if(temp->left != NULL && temp->right == NULL)
                           return temp->data=sumNode(temp->left);
               else if(temp->left == NULL && temp->right != NULL)
                           return temp->data=sumNode(temp->right);
              else
                     return temp->data;             
      }
      else 
        return 0;
}      
*/    
          
                          
int isSumTree(node* temp)
{
    if(temp != NULL)
    {
       if(temp->left != NULL && temp->right != NULL)
       {
            if(temp->data == isSumTree(temp->left)+isSumTree(temp->right)) 
{                          return temp->data = temp->data + isSumTree(temp->left)+isSumTree(temp->right);
 }
            else
             return 0;
       }
       else 
            return temp->data;
     }
     else
         return 0;
}                    
  
            
            
    
    
                         
                                             
     
            
    
