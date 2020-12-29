//Implementation of stack using linked list
#include<stdlib.h>
#include<stdio.h>
void push();
void pop();
void display();
void exit();
struct node
{
 int data;
 struct node *link;
};
struct node *top=NULL;
void main()
{
 int choice;
 printf("----------STACK OPERATIONS----------\n");
 printf(" \n1.PUSH\t 2.POP\t 3.DISPLAY\t 4.EXIT\n");
 do
 {
   
   printf("Enter the choice:\n");
   scanf("\n%d",&choice);
   switch(choice)
    {
      case 1:push();
             break;
      case 2:pop();
             break;
      case 3:display();
             break;
      case 4:printf("exit....\n");
             exit(0);
             break;
      default:printf("Wrong choice!!!Enter a valid choice(0-4).\n");
             break;
    }//end of switch
 }while(choice!=4);
}//end of main

void push()
{ 
  
  struct node *newnode;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter the data to be inserted into the stack:");
  scanf("%d",&newnode->data);
  newnode->link=top;
  top=newnode;
}//end of pop function

void pop()
{
  struct node *temp;
  temp=top;
  if(top==NULL)
  {
     printf("Stack underflow!!\n");
  }
 else
  {
    printf("The popped element is:%d\n",top->data);
    top=top->link;
    free(temp);
  }
}//end of pop function

void display()
{
 struct node *temp;
  temp=top;
   if(top==NULL)
  {
    printf("Stack underflow!!\n");
  }
  else
  {
    while(temp!=NULL)
    {
       printf("%d",temp->data);
       temp=temp->link;
     }
    printf("\n");
  }
}//end of display function