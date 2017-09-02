#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
void reverse_doublylinkedlist(struct node* &head)
{
    struct node* temp=head;
    struct node* nexttemp=head->next;
    while(nexttemp!=NULL)
    {
        swap(temp->prev,temp->next);
        temp=nexttemp;
       // if(nexttemp!=NULL)
            nexttemp=nexttemp->next;
    }
    swap(temp->next,temp->prev);
    head=temp;
}
void insert_at_front(int x,struct node* &head)
{
    struct node* temp=new node;
    temp->data=x;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        return;
    }
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void print(struct node* head)
{
    struct node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
cout<<endl;
}
int main()
{
    struct node* head=NULL;
    int n;
    cin>>n;//number of elements need to be inserted
    while(n--)
    {
        int x;
        cin>>x;
        insert_at_front(x,head);
    }
    print(head);
     reverse_doublylinkedlist(head);
     print(head);
 return 0;
}
