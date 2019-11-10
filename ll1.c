#include<stdio.h>
#include<stdlib.h>
struct Node
{
  int data;
  struct Node *next;
} *head,*prev;

void add(int d)
{
  struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));

  if(head==NULL)
  {
    head=(struct Node*)malloc(sizeof(struct Node));
    head->data=d;
    head->next=NULL;
    prev=head;
  }
  else
  {
    tmp->data=d;
    tmp->next=NULL;
    prev->next=tmp;
    prev=tmp;

  }
}

void delete(int pos)
{
  struct Node* node;
  node=head;
  int count=1;
  if(pos==1)
  {
    node=head->next;
    head=node;
    return;
  }
  while(count<pos-1)
  {
    node=node->next;
    count++;
  }
  struct Node*link = node->next->next;
  node->next=link;
}


void printList()
{
  struct Node *node;
  node=head;
  while(node!=NULL)
  {
    printf("%d\n",node->data);
    node=node->next;
  }
}

int main()
{
  int i,n,val,pos;
  printf("Enter n \n");
  scanf("%d",&n);

  printf("enter elements in linked list\n");
  for(i=0;i<n;i++)
  {
    scanf("%d",&val);
    add(val);
  }
  printf("your linked list is \n");
  printList();

  printf("Enter pos to be deleted\n");
  scanf("%d",&pos);

  delete(pos);

  printf("after deletion\n");
  printList();

  return 0;
}
