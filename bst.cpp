#include<bits/stdc++.h>
using namespace std;
struct Node
{
  int key;
  struct Node *left,*right;
};

struct Node *newNode(int item)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

void inorder(struct Node *root)
{
  if(root!= NULL)
  {
    inorder(root->left);
    printf("%d\n",root->key);
    inorder(root->right);
  }
}
struct Node* insert(struct Node *node,int key)
{
  if(node==NULL)
  {
    return newNode(key);
  }
  if(key<node->key)
  {
    node->left = insert(node->left,key);
  }
  else if(key>node->key)
  {
    node->right = insert(node->right,key);
  }
//  return node;
}

void search(struct Node *root,int key)
{
  if(root==NULL)
  {
    printf("Not Found\n");
  }
  else if(key==root->key)
  {
    printf("Key Found\n");
  }
  else if(key<root->key)
  {
    search(root->left,key);
  }
  else if(key>root->key)
  {
    search(root->right,key);
  }
}
void min(struct Node *node)
{
  while(node->left!=NULL)
  {
    node=node->left;
  }
  printf("%d",node->key );
}

int kthsmallest(struct Node *root,int k)
{
  static int c=1;
  if(root!=NULL)
  {
    if(kthsmallest(root->left,k)==0)
    {
      return 0;
    }
    if(c==k)
    {
      printf("%d\n",root->key);
      return 0;
    }
    c++;
    if(kthsmallest(root->right,k)==0)
    {
      return 0;
    }

  }
  return 1;
}


bool isRoot(struct Node *root,int item)
{
  while(true)
  {
    if(root==NULL)
    {
      return false;
    }
    if(item<root->key)
    {
      root=root->left;
    }
    else if(item>root->key)
    {
      root=root->right;
    }
    else if(item==root->key)
    {
       return true;
    }
  }
}

void lca(struct Node *root,int a,int b)
{
   int com_root;
   while(root->key!=a)
   {
     if(isRoot(root,b))
     {
        com_root = root->key;
     }
     if(a<root->key)
     {
       root=root->left;
     }
     else if(a>root->key)
     {
       root=root->right;
     }
   }
   printf("%d\n",com_root);
}

int lessThanEqualTo(struct Node *root,int item)
{
  int result=0;
  while(root!=NULL)
  {
    if(root->key==item)
    {
      return root->key;
    }
    if(item<root->key)
    {
      root=root->left;
    }
    else if(root->key<item)
    {
      result  = root->key;
      root=root->right;
    }
  }
  return result;
}
int main()
{
  struct Node *root = NULL;
  root = insert(root,50);
  insert(root,30);
  insert(root,20);
  insert(root,40);
  insert(root,70);
  insert(root,60);
  insert(root,80);

  search(root,80);

  inorder(root);

//  min(root);

//  printf("\nenter k\n");
//  int k;
//  scanf("%d\n",&k);
//  kthsmallest(root,k);
//  printf("Least Common root is = ");
//  lca(root,70,40);

  printf("%d",lessThanEqualTo(root,25));
  return 0;
}
