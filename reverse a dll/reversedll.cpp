#include<iostream>

using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};

void printdll(Node* head);
void push(Node** head,int item);
void reversedll(Node** head)
{
    Node *temp = NULL;  
    Node *current = *head;  
      
    /* swap next and prev for all nodes of  
    doubly linked list */
    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  
      
    /* Before changing the head, check for the cases like empty  
        list and list with only one node */
    if(temp != NULL )  
        *head= temp->prev;
}

void push(Node** head,int item)
{
    Node *new_node=new Node(item);

    new_node->next=(*head);
    new_node->prev=NULL;
    if((*head)!=NULL)
    {
        (*head)->prev=new_node;
    }
    
    (*head)=new_node;
}

void printdll(Node *head)
{
    Node *ptr=head;
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
    Node *head=NULL;
    int n,item;
    cout<<"How many values you want to add to DLL:";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"\nEnter item :";
        cin>>item;
        push(&head,item);

    }
    cout<<"Original DLL:";
    printdll(head);
    reversedll(&head);
    cout<<"Reversed DLL:";
    printdll(head);
    cout<<endl;
    return 0;
}
