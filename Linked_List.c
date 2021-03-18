#include<stdlib.h>
#include <stdio.h>
void Create();
void insert_end();
void insert_beg();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void display();
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;
int count=0;
int main()     
{
              int choice;
                printf("1.Create    \n");
                printf("2.insert at end     \n");
                printf("3.insert at beginning    \n");
                printf("4.insert at position    \n");
                printf("5.Delete at beginning   \n");
                printf("6.Delete at end    \n");
                printf("7.Delete at position    \n");
                printf("8.Display    \n");
                printf("9.Quit    \n");

        do{   
                printf("Enter your choice:\t");
                scanf("%d",&choice); 
               
                switch(choice)
                {
                        case 1:
                                        Create();
                                        break;
                        case 2:
                                        insert_end();
                                        break;
                        case 3:
                                        insert_beg();
                                        break;
                        case 4:
                                        insert_pos();
                                        break;
                        case 5:
                                        delete_beg();
                                        break;
                        case 6:
                                        delete_end();
                                        break;
                        case 7:
                                        delete_pos();
                                        break;
                        case 8:
                                        display();
                                        break;
                        case 9: 
                                        exit(0);
                                        break;
                    
                        default:
                                        printf("Wrong Choice:\n");
                                        break;
                }
        }while(choice!=9);
        return 0;
}
void Create()
{
        struct node *new,*temp;
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data value for the node:");
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL)
        {
                head=new;
        }
        else
        {
                temp=head;
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=new;
        }
}
void insert_beg()
{
  struct node *new,*temp;
  new=(struct node *)malloc(sizeof(struct node));
  printf("Enter the data you want to insert at beginning:");
  scanf("%d",&new->data);
  if(head==NULL)
 {
  head=new;
 }
 else
 {
  new->next=head;
  head=new;
 }
}

void insert_end()
{
        struct node *new,*temp;
        new=(struct node *)malloc(sizeof(struct node));
        printf("Enter the data value for the node:");
        scanf("%d",&new->data);
        new->next=NULL;
        if(head==NULL)
        {
                head=new;
        }
        else
        {
                temp=head;
                while(temp->next!=NULL)
                {
                        temp=temp->next;
                }
                temp->next=new;
        }
}
void insert_pos()
{
struct node *new,*temp;
 int pos,i;
new=(struct node *)malloc(sizeof(struct node));
  if(new == NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter the value to be inserted:");  
        scanf("%d",&new->data);  
       // ptr->data = item;  
        printf("\nEnter the position after which you want to insert ");  
        scanf("%d",&pos);  
        temp=head;  
        for(i=1;i<pos;i++)  
        {  
            temp = temp->next;  
            if(temp == NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
          
        }  
        new ->next = temp ->next;   
        temp ->next = new;   
 }
 
}
void delete_beg()  
{  
    struct node *new;  
    if(head == NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        new = head;  
        head = new->next;  
        free(new);   
    }  
}  
void delete_end()  
{  
    struct node *new,*temp;  
    if(head == NULL)  
    {  
        printf("\nlist is empty");  
    }  
    else if(head -> next == NULL)  //if only one element is in the list
    {  
        head = NULL;  
        free(head);  
       
    }  
          
    else  
    {  
        new = head;   
        while(new->next != NULL)  
        {  
            temp = new;  
            new = new ->next;  
        }  
        temp->next = NULL;  
        free(new);  
        
    }     
}  
void delete_pos()  
{  
    struct node *new,*temp;  
    int pos,i;    
    printf("\n Enter the location of the node after which you want to perform deletion \n");  
    scanf("%d",&pos);  
    new=head;  
    for(i=1;i<pos;i++)  
    {  
        temp = new;       
        new = new->next;  
              
        if(new == NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }  
    temp ->next = new ->next;  
    free(new);  
    
}  
void display()
{  
        
        struct node *temp;
        if(head==NULL)
        {
                printf("List is empty:\n");
                return;
        }
        else
        {
                temp=head;
                printf("The List elements are:\n");
                while(temp!=NULL)
                {
                        printf("%d\t",temp->data );
                        temp=temp->next ;
                        count++;
                }
                printf("\n"); 
        }
}
