#include<stdio.h>
void insert();
void delete();
void display();
int queue[100],choice,i,n;
int front=-1;
int rear=-1;
int main()
{
  printf("Enter the size of the queue\n");
scanf("%d",&n);
  printf("----------QUEUE OPERATIONS------------\n");
  printf("1.Insertion\n2.Deletion\n3.Display\n4.Quit\n");
  do
  { 
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch(choice)
    { 
      case 1:insert();
            break;
      case 2:delete();
            break;
      case 3:display();
            break;
      case 4:printf("quiting...\n");
             break;
       default:printf("Enter a valid choice\n");

    }//switch
  }//while
while(choice!=4);
return 0;
}//main
void insert()
{ 
int item;
if(rear==n-1)
{
 printf("Cannot insert element!!Queue overflow\n");

} 
else
{
 if(front==-1)
    front=0;
  printf("Enter the value to be added in the queue:");
  scanf("%d",&item);
  rear=rear+1;
  queue[rear]=item;
}


}//insert
void delete()
{
  if(front == - 1 || front > rear)
{
  printf("deletion not possible!!..Queue underflow\n");
  return;
 }
else
{
 printf("Deleted element id %d",queue[front]);
front=front+1;
 
}
}
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
        printf("\n");
    }
}
