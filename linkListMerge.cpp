#include<iostream>
using namespace std;
struct list
{
int data;
list *next;
}*head1=NULL,*head2=NULL;

list* create_node(int n)
{
  list *temp=new list();
  temp->next=NULL;
  temp->data=n;
  return temp;
}

void insert(list**head,int n)
{
  list *temp=create_node(n);
  if(*head==NULL)
  {
    *head=temp;
    return;
  }
  temp->next=*head;
  *head=temp;
}

void traverse(list*head)
{
  if(head==NULL)
  return;
  cout<<head->data<<" ";
  traverse(head->next);
}

void merge(list*temp1,list*temp2)
{
  list *common=temp1;
  temp1=temp1->next;
  int i=0;
  while(temp1!=NULL&&temp2!=NULL)
  {
    if(i%2==0)
    {
      common->next=temp2;
      common=common->next;
      temp2=temp2->next;
    }
    else
    {
      common->next=temp1;
      common=common->next;
      temp1=temp1->next;
    }
    i++;
  }
  if(temp1!=NULL)
  common->next=temp1;
  else common->next=temp2;

}


int main()
{
  int n,x;
  cout<<"Enter the number of elements in list 1 \t";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    insert(&head1,x);
  }
  cout<<"Enter the number of elements in list 2 \t";
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    insert(&head2,x);
  }
  traverse(head1);
  cout<<endl;
  traverse(head2);
  cout<<endl;
  merge(head1,head2);
  traverse(head1);

}
