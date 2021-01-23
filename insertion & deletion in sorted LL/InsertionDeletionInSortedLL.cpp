#include <iostream>

using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void insertnode(node **head, int item);
void deletenode(node **head, int item);
void printdll(node *head);

void insertnode(node **head, int item)
{
    node *new_node = new node(item);
    new_node->data = item;
    if(*head==NULL)
    {
    new_node->next = *head;
    *head = new_node;
    return;
    }

    if(item<((*head)->data))
    {
        new_node->next=*head;
        *head=new_node;
        return;
    }
    node *ptr=*head,*prevn=*head;
    while (ptr!=NULL && ptr->data<item)
    {
        prevn=ptr;
        ptr=ptr->next;
    }

    new_node->next=prevn->next;
    prevn->next=new_node;
}

void deletenode(node **head, int item)
{
    if (*head == NULL)
    {
        cout<<"No element present in Linked list\n";
        return;
    }

    node *del = *head, *prevn = *head;
    if (del->data == item)
    {
        (*head) = (*head)->next;
        free(del);
        return;
    }

    while (del != NULL && del->data<=item)
    {
        if(del->data==item)
        break;
        prevn = del;
        del = del->next;
    }
    
    if(del->data!=item)
    {
        cout<<"\nElement not found\n";
        return;
    }



    prevn->next = del->next;
    free(del);
}

void printdll(node *head)
{
    node *ptr = head;
    cout<<"\n";
    while (ptr != NULL)
    {
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<"NULL\n";
}

int main()
{
    node *head = NULL;
    int n, item;
    char ch;
    cout<<"Do you want to enter elements in the Linked List(y or n):";
    cin>>ch;
    while (ch == 'y' || ch == 'Y')
    {
        cout<<"1.Insertion of node\n";
        cout<<"2.Delete a Node\n";
        cout<<"3.Quit\n";
        cout<<"Enter your choice:";
        cin>>n;

        switch (n)
        {
        case 1:
            cout<<"Enter the data:";
            cin>>item;
            insertnode(&head, item);
            break;
        case 2:
            cout<<"Enter the data of the node you want to delete:";
            cin>>item;
            deletenode(&head, item);
            break;
        default:
            exit(0);
            break;
        }
        cout<<"Linked List: ";
        printdll(head);
        cout<<"\nDo you want to continue (y or n):";
        cin>>ch;
        system("cls");
    }
    system("pause");
    return 0;
}