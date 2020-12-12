#include<stdio.h>
int stack[50],i,n,choice,value;
 int top=-1;
void push();
void pop();
void display();
int main()
{


 printf("Enter the number of elements in the stack[MAX=50]");
 scanf("%d",&n);
 printf("---------------STACK OPERATIONS---------------------\n");
 printf("1.PUSH\n2.POP\n3.DISPLAY\n4.QUIT\n");
 do
{
 printf("Enter the choice:");
 scanf("%d",&choice);
 switch(choice)
 {
   case 1:push();
         break;
  case 2:pop();
         break;
   case 3:display();
         break;
 case 4:printf("Closing..\n");
         break;
  default:printf("wrong choice!!!..Enter a valid choice\n");
         break;
}//switch
 
}//do
while(choice!=4);
return 0; 
}//main

void push()
{
 if(top>=n-1)
{
 printf("Cannot push elements!!Stack is overflow!!\n");
}
else
{
printf("Enter the value to be pushed:");
scanf("%d",&value);
top++;
stack[top]=value;
}
 
}//end of push

void pop()
{
 if(stack[top]<-1)
 { 
  printf("Cannot POP anymore elements!!Stack undeflow!!");
 }
else
{
printf("The popped element is : %d \n",stack[top]);
top--;
}
}
void display()
{
 if(top>=0)
{
printf("The stack elements are:\n");
for(i=top;i>=0;i--)
{ 
 printf("%d\n",stack[i]);
}
}
//printf("Enter the next choice:\n");
else
{
printf("Stack is empty\n");
}//else
}


