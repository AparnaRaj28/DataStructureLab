#include<stdio.h>
int main()
{
	int arr1[50],arr2[50],arr3[100],i,j,size1,size2,temp;
	printf("Enter the size of the first array:");
	scanf("%d",&size1);
	printf("Enter %d elements:\n",size1);
	for(i=0;i<size1;i++)
	{
		scanf("%d",&arr1[i]);
		arr3[i]=arr1[i];
		
	}
	printf("Enter the size of the second array:");
	scanf("%d",&size2);
	printf("Enter %d elements:\n",size2);
	for(i=0;i<size2;i++)
	{
		scanf("%d",&arr2[i]);
		arr3[size1+i]=arr2[i];
	}
	//sorting arr3
	for(i=0;i<(size1+size2);i++)
	{
		for(j=0;j<(size1+size2);j++)
		{
			if(arr3[i]<arr3[j])
			{
                           temp=arr3[i];
                           arr3[i]=arr3[j];
                           arr3[j]=temp;
			}
		}
	}
       printf("The merged array is:");
           for(i=0;i<(size1+size2);i++)
          {
	    printf("%d\t",arr3[i]);
	   }	
	
	return 0;
}//end of main