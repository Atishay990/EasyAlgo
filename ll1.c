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

void reverse(int n)
{
  int i=1;
  struct Node* cur=head;
  struct Node* pre = NULL;
  struct Node* nex = NULL;
//  tmp->next=h->next;
  printf("mudda\n");
  while(cur!=NULL)
  {
    nex=cur->next;
    cur->next=pre;
    pre=cur;
    cur=nex;
  }
  printf("Reversed\n");
  head=pre;

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

  printf("Enter 1 if you want to reverse the linked list\n");
  int r;
  scanf("%d",&r);
  if(r==1)
  {
    reverse(n);
    printf("Linked list after reversing is = \n");
    printList();
  }

  return 0;
}
