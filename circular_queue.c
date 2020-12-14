#include<stdio.h>
void enqueue();
void dequeue();
void display();
int front=-1;
int rear=-1;
int n,item,queue[100],choice;
int main()
{
printf("Enter the size of the queue:");
scanf("%d",&n);
printf("------------QUEUE OPERATIONS-------------\n");
printf("1.Insert\n2.Delete\n3.Display\n4.Quit\n");

do
{
printf("Enter the choice:");
scanf("%d",&choice);
 switch(choice)
{
    case 1: enqueue(); 
                   break;
    case 2: dequeue(); 
                   break;
    case 3: display(); 
                   break;
    case 4: printf("Quiting...\n"); 
                   break;
    default: printf("Invalid choice!!....Enter a valid choice"); 
                   break;
}//end of switch
}//end of do
 while(choice!=4);
}//end of main
void enqueue()
{
   int item;
 printf("Enter the element to be inserted into the queue:");
scanf("%d",&item);
 if(front==-1 && rear==-1)      //condition when queue is empty
    {
       front=0;
        rear=0;
       queue[rear]=item;
      }
else if(((rear+1)%n) == front )     // Overflow condition
   {
             printf("Queue overflow!!Cannot insert anymore elements.\n");
    }
else
  {
              rear=(rear+1)%n;
              queue[rear]=item;
   }
}//end of enqueue function

void dequeue()
{
if(front==-1 && rear==-1)    //if queue is empty
{
    printf("Queue underflow!!Cannot delete element\n"); 
}
else if(front==rear)   // if there is only one element in queue
{
    printf("The deleted element is  :%d",&queue[front]);
    front=-1;
    rear=-1;
}
else
{
    printf("The deleted element is : %d",&queue[front]);
    front=(front+1)%n;
}
}//end of dequeue function

void display()
{
int i=front;
if(front==-1 && rear==-1)    //if queue is empty
{
    printf("Queue is Empty"); 
}
else
{
printf("Queue is:\n");
while(i!=rear)
{
printf("%d\t",queue[i]);
i=(i+1)%n;
}
printf("%d",queue[rear]);//print the last element
printf("\n") 
}

}//end of display function