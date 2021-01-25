#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node* left;
  struct node* right;
};
struct node *create(int x)
{
 struct node *newnode;
 newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=x;
 newnode->left=NULL;
 newnode->right=NULL;
 return newnode;
}

struct node* insert(struct node *root, int x)
{
    //searching for the place to insert
    if(root==NULL)
     {
        return create(x);
      }
    else if(x>root->data) // x is greater. Should be inserted to right
      {
        root->right = insert(root->right, x);
      }
    else // x is smaller should be inserted to left
      {
        root->left= insert(root->left,x);
      }
    return root;
}
//function to find the minimum value in a node
struct node* find_minimum(struct node *root)
{
    if(root == NULL)
         {
          printf("There is no element in the tree to delete!!\n");
         }
    else if(root->left != NULL) // node with minimum value will have no left child
        return find_minimum(root->left); // left most element will be minimum
    return root;
}
struct node* delete(struct node *root, int x)
{
    if(root==NULL)
        {
          printf("There is no element in the tree to delete!!\n");
         }
    if (x>root->data)
       {
        root->right = delete(root->right, x);
        }
    else if(x<root->data)
       {
        root->left = delete(root->left, x);
       }
    else
    {
        //No Children
        if(root->left==NULL && root->right==NULL)
        {
            free(root);
            return NULL;
        }

        //One Child
        else if(root->left==NULL || root->right==NULL)
        {
            struct node* temp;
            if(root->left==NULL)
                temp = root->right;
            else
                temp = root->left;
            free(root);
            return temp;
        }

        //Two Children
        else
        {
            struct node *temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}

void traversal(struct node *root)
{
    if(root!=NULL) // checking if the root is not null
    {
        traversal(root->left); // visiting left child
        printf(" %d ", root->data); // printing data at root
        traversal(root->right);// visiting right child
    }
}



int main()     
{
           int item;
           struct node* root;
           
              int choice;
                printf("1.Create    \n");
                printf("2.insert   \n");
                printf("3.Delete   \n");
                printf("4.traverse    \n");
                printf("5.Quit    \n");

        do{   
                printf("Enter your choice:\t");
                scanf("%d",&choice); 
               
                switch(choice)
                {
                        case 1:
                                         printf("Enter the element:");
                                         scanf("%d",&item);
                                         root=create(item);
                                         break;
                        case 2:
                                                                                
                                        printf("Enter the element:");
                                        scanf("%d",&item);
                                        insert(root,item);
                                        break;
                        case 3:
                                        printf("Enter the element to be deleted:");
                                        scanf("%d",&item);
                                        root=delete(root,item);
                                        break;
                        
                        case 4:
                                        traversal(root);
                                        break;
                        case 5: 
                                        exit(0);
                                        break;
                    
                        default:
                                        printf("Wrong Choice:\n");
                                        break;
                }
        }while(choice!=9);
        return 0;
}