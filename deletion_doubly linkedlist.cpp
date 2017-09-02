#include <iostream>

using namespace std;
struct node
{
    int data;
    struct node* next;
    struct node* prev;
};
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
void deletenode(int x,struct node* &head)
{
    struct node* temp=head;
    while(temp!=NULL && temp->data!=x )
    {
        temp=temp->next;
    }
    if(temp==NULL)
        {
           cout<<"not present"<<endl;
           return;
        }
    if(temp->prev==NULL && temp->next==NULL)
    {
        cout<<"list is empty"<<endl;
        head=NULL;
        return;
    }
    if(temp->prev==NULL)
    {
        head=temp->next;
        head->prev=NULL;
        return;
    }
    if(temp->next==NULL)
    {
        temp=temp->prev;
        temp->next=NULL;
        return;
    }
    else
    {
        struct node* prevtemp=temp->prev;
        struct node* nexttemp=temp->next;
        prevtemp->next=nexttemp;
        nexttemp->prev=prevtemp;
    }
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
n=0;
    cin>>n;
while(n--)
{
    int x;
    cin>>x;
    deletenode(x,head);
    print(head);
}

    return 0;
}
