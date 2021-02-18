//cd onedrive\desktop\dslab
//gcc DisjointSet.c -o ds
#include<stdio.h>
#include<stdlib.h>
void MakeSet();
void Display();
int findparent(int x);
void FindSet(int x,int y);
void UnionSet(int x,int y);
int v[50],x,y,n,i,item,flag=0;
int main()
{

  printf("DISJOINT SET OPERATIONS\n----------------------\n");
 printf("1.Make Set\n");
 printf("2.Display set\n");
 printf("3.Union\n");
 printf("4.Find\n");
 printf("5.QUIT\n------------------------\n");
 int choice;
 do
{
  printf("Enter choice:");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1: MakeSet();
           break;
   case 2: Display();
           break;
   case 3: printf("Enter the nodes to get union:\n");
           scanf("%d\n%d",&x,&y);
           UnionSet(x,y);
           break;
   case 4: printf("Enter two nodes:\n");
           scanf("%d\n%d",&x,&y);
           FindSet(x,y);
           break;
   case 5: printf("Quiting..\n");
           break;
   default:printf("Wrong choice!!\n");
           break;
 }
}
while(choice!=5);
return 0;
}

void MakeSet()
{ 
  // int item,i;
   printf("Enter the number of nodes:\n");
   scanf("%d",&n);
   printf("Enter the elements:");
   for(i=0;i<n;i++)
   {
       scanf("%d",&item);
       v[i]=item;
    }
    
}
void Display()
{
 printf("The elements are:\n");
 for(int i=0;i<n;i++)
  {
    printf("%d\t",v[i]);
  }
  printf("\n");
}

int findparent(int x)
{
    while(v[x] != x)
    {
        x = v[x];
    }
    return x;
}

void FindSet(int x,int y)
{
    if(findparent(x) == findparent(y))
        printf("Both the nodes are from the same set\n");
    else
        printf("Both the nodes are from different sets\n");
}

void UnionSet(int x,int y)
{
    for(i=0;i<n;i++)
    {
      if(x==v[i])
      {
        flag++;
      }
    }

    if(flag>0)
   {
    int i = findparent(x);
    int j = findparent(y);
    v[ i ] = j;
   }
  else
  { 
    printf("The element is not present in the set\n");
  }

}
