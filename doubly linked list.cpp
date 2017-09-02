#include <iostream>

using namespace std;
struct node{
int data;
node* prev;
node* next;
};
void insert_at_front(int x,struct node* &head)
{
    struct node* temp=new node;
    temp->data=x;
    temp->prev=NULL;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
    temp->next=head;
    head->prev=temp;
    head=temp;
    }
}
void insert_at_last(int x,struct node* &head)
{
    struct node* prevtemp=head;
    struct node* temp = new node;
    temp->data=x;
    temp->next=NULL;
    if(head==NULL)
        head=temp;

    else{

         while(prevtemp->next!=NULL)
         {
             prevtemp=prevtemp->next;
         }
         prevtemp->next=temp;
        }
        temp->prev=prevtemp;
}
void print(struct node* &head)
{
     struct node* temp=head;
   while(temp!=NULL)
   {
       cout<<temp->data<<" ";
       temp=temp->next;
   }
}
int main()
{
    struct node* head=NULL;
   int n,ch;
   cin>>n;
   cout<<"enter choice"<<endl;
   cin>>ch;
   switch (ch)
   {
       case 1:
   {
       while(n--)
   {
       int x;
       cin>>x;
        insert_at_last(x,head);
   }
   }
   break;
   case 2:
   {
       while(n--)
       {
           int x;
       cin>>x;
       insert_at_front(x,head);
       }
   }


   }
  print(head);
    return 0;
}
