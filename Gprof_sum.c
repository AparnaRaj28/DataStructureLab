#include<stdio.h>
int sum(int,int);
int main()
{
 int num1,num2,total;
 printf("Enter two numbers:\n");
 scanf("%d%d",&num1,&num2);
 total=sum(num1,num2);
 printf("The sum is:%d",total);
 return 0;
}
 
int sum(int a,int b)
{
 int result=a+b;
 return result;
}