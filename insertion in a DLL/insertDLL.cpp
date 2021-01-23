#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void push(node **head,int item);
void insertbefore(node **head,int item,int pos);
void insertafter(node **head,int item,int pos);
void insertlast(node **head,int item);
void printdll(node *head);

void push(node **head,int item)
{
    node *new_node=new node(item);
    new_node->next=*head;
    if(*head!=NULL)
    (*head)->prev=new_node;

    *head=new_node;
}

void insertbefore(node **head,int item,int pos)
{
    node *nextn=*head;
    node *new_node=new node(item);

    for(int i=1;i<pos;i++)
    {
        nextn=nextn->next;
    }

    new_node->next=nextn;
    new_node->prev=nextn->prev;
    nextn->prev=new_node;

    if(new_node->prev!=NULL)
    {
        new_node->prev->next=new_node;
    }
    else
    {
        *head=new_node;
    }
    


}

void insertafter(node **head,int item,int pos)
{
    node *prevn=*head;
    node *new_node=new node(item);

    for(int i=1;i<pos;i++)
    {
        prevn=prevn->next;
    }

    new_node->prev=prevn;
    new_node->next=prevn->next;
    prevn->next=new_node;

if(new_node->next!=NULL)
     new_node->next->prev=new_node;



}

void insertlast(node **head,int item)
{
    node *last=*head;
    node *new_node=new node(item);

    if(*head==NULL)
    {
        *head=new_node;
        return;
    }
    while(last->next!=NULL)
    {
        last=last->next;
    }

    last->next=new_node;
    new_node->prev=last;
}

void printdll(node *head)
{
    node *ptr=head;
    cout<<"\n";
    while(ptr!=NULL)
    {
        cout<<ptr->data<<"<->";
        ptr=ptr->next;
    }
    cout<<"NULL"<<endl;
}

int main()
{
    node *head = NULL;

    int n,item,pos;
    char ch;
    cout << "Do you want to enter elements in the DLL(y or n):";
    cin >> ch;
    while (ch == 'y' || ch == 'Y')
    {
        cout << "1.Insertion in front\n";
        cout << "2.Insertion before a node\n";
        cout << "3.Insertion after a node\n";
        cout << "4.Insertion at end\n";
        cout << "5.Quit\n";
        cout << "Enter your choice:";
        cin >> n;

        switch (n)
        {
        case 1:
            cout << "Enter the data:";
            cin >> item;
            push(&head, item);
            break;
        case 2:
            cout << "Enter the data:";
            cin >> item;
            cout<<"\nEnter the position before which you want to insert:";
            cin>>pos;
            insertbefore(&head, item, pos);
            break;
        case 3:
            cout << "Enter the data:";
            cin >> item;
            cout<<"\nEnter the position after which you want to insert:";
            cin>>pos;
            insertafter(&head, item, pos);
            break;
        case 4:
            cout<<"Enter the data:";
            cin>>item;
            insertlast(&head,item);
            break;
        default:
            exit(0);
            break;
        }
        cout<<"Updated DLL: ";
        printdll(head); 
        cout<<"\nDo you want to continue (y or n):";
        cin>>ch;
    }
}