#include<stdio.h>
#include<stdlib.h>
void create();
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
 struct node *prev;
};
struct node *head=NULL;
struct node *tail;

int main()     
{
                printf("1.Create    \n");
                printf("2.Insert at end     \n");
                printf("3.Insert at beginning    \n");
                printf("4.Insert at position    \n");
                printf("5.Delete at beginning   \n");
                printf("6.Delete at end    \n");
                printf("7.Delete at position    \n");
                printf("8.Display    \n");
                printf("9.Quit    \n");
        int choice;
        do{
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        create();
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
void create()
{
 struct node *newnode;
 //temp = head;
 newnode=(struct node *)malloc(sizeof(struct node));
 printf("Enter the data to be inserted:");
 scanf("%d",&newnode->data);
 newnode->prev=NULL;
 newnode->next=NULL;
 if(head==NULL)
  {
    head=tail=newnode;
  }
 else
 { 
   
  tail->next=newnode;
  newnode->prev=tail;
  tail=newnode;
 }
}
void insert_beg()  
{  
   struct node *newnode;   
   //int item;  
   newnode = (struct node *)malloc(sizeof(struct node));  
  
    printf("\nEnter the value to be inserted:");  
    scanf("%d",&newnode->data);  
      
   if(head==NULL)  
   {  
       newnode->next = NULL;  
       newnode->prev=NULL;  
       //newnode->data=item;  
       head=newnode;  
   }  
   else   
   {  
       //newnode->data=item;  
       newnode->prev=NULL;  
       newnode->next = NULL;  
       head->prev=newnode; 
       newnode->next=head; 
       head=newnode; 
     } 
     
   
}  
void insert_end()  
{  
   struct node *newnode;  
   //int item;  
   newnode = (struct node *) malloc(sizeof(struct node));  

       printf("\nEnter the value to be inserted at the end:");  
       scanf("%d",&newnode->data);  
       newnode->prev=NULL;
       newnode->next=NULL;
       tail->next=newnode;
       newnode->prev=tail;
       tail=newnode;
       
} 
void insert_pos()  
{  
   struct node *newnode,*temp;  
   int pos,i;  
   newnode = (struct node *)malloc(sizeof(struct node));  
  
       temp=head;  
       printf("Enter the position after which you want to insert:");  
       scanf("%d",&pos);  
       for(i=1;i<pos;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("invalid position");  
               return;  
           }  
       }  
       printf("Enter the value to be inserted :");  
       scanf("%d",&newnode->data);        
       newnode -> prev = temp; 
       newnode->next = temp->next;  
       temp->next = newnode;  
       newnode->next->prev=newnode;  
     
    
} 
void delete_beg()  
{  
    struct node *temp;  
    if(head == NULL)  
    {  
        printf("\n UNDERFLOW");  
    }  
    else 
    {  
       temp=head;
       head=head->next;
       head->prev=NULL;
       free(temp);
        printf("\nnode deleted\n");  
    }  
  
}  
void delete_end()  
{  
    struct node * temp;
if(head == NULL)
{
printf("Unable to delete. List is empty.\n");
}
else
{
temp = tail;
tail->prev->next=NULL;
tail=tail->prev;
free(temp);
printf("\nNode deleted\n");
}  
}
void delete_pos()  
{   
    struct node *temp;
    int pos;
    temp=head;
    printf("Enter the position of the element to be deleted:");
    scanf("%d",&pos);
   for(int i=1;i<pos;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("invalid position");  
               return;  
           }  
       }  
  temp->prev->next=temp->next;
  temp->next->prev=temp->prev;
  free(temp);
        
}    
void display()
{ 
 struct node *temp;
 temp=head;
 while(temp!=NULL)
 {
  printf("%d\t",temp->data);
  temp=temp->next;
 }
 printf("\n");
}