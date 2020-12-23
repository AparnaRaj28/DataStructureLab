#include<stdlib.h>
#include <stdio.h>
void create();
void display();
struct node
{
        int data;
        struct node *next;
};
struct node *head=NULL;
int main()     
{
                printf("1.Create     \n");
                printf("2.Display    \n");
                printf("3.Quit    \n");
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
                                        display();
                                        break;
                        case 3: 
                                        exit(0);
                                        break;
                    
                        default:
                                        printf("Wrong Choice:\n");
                                        break;
                }
        }while(choice!=3);
        return 0;
}
void create()
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
                }
                printf("\n"); 
        }
}