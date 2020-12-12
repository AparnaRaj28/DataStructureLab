#include<stdio.h>
int main()
{
int arr[100],n,choice,i,pos;
printf("Enter the number of elements in the array:");
scanf("%d",&n);
printf("Enter the array elements:\n");
for(i=0;i<n;i++)
{
 scanf("%d",&arr[i]);
}
printf("Enter the position where you want to delete the element:");
scanf("%d",&pos);
if(pos<0 || pos >n)
{
 printf("Enter a valid position !!\n");
}
else
{
 for(i=pos-1;i<n-1;i++)
{
 arr[i]=arr[i+1];
}
n--;
printf("array elements after deletion:\n");
for(i=0;i<n;i++)
{
 printf("%d\n",arr[i]);
}
} 
return 0;
}
 