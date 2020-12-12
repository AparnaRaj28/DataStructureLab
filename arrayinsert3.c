//program to insert an element in an array
#include<stdio.h>

int main()
{
  int array[100],n,i,value,pos;
 printf("\tEnter the number of elements in the array:");
 scanf("%d",&n);
 printf("\tEnter the array elements:\n"); 
 for(i=0;i<n;i++)
{
 scanf("%d",&array[i]);
}

 printf("\tEnter the position where you wish to insert the element:");
 scanf("%d",&pos);
 printf("\tEnter the value to be inserted:");
 scanf("%d",&value);
 
 for(i=i-1;i>=pos-1;i--)
{
    array[i+1]=array[i];
    
}
 array[pos-1]=value;
 printf("\tThe resultant array is:\n");
 for(i=0;i<=n;i++)
{
   printf("%d\n",array[i]);
}

return 0;

}