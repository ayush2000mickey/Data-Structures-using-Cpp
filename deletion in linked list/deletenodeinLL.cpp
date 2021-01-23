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
void push(node **head, int item);
void insertafter(node **head, int item, int pos);
void insertlast(node **head, int item);
void deletenode(node **head, int item);
void printdll(node *head);

void push(node **head, int item)
{
    node *new_node = new node(item);
    new_node->data = item;
    new_node->next = *head;
    *head = new_node;
}

void insertafter(node **head, int item, int pos)
{

    node *prev_node = *head;
    for (int i = 1; i < pos; i++)
    {
        prev_node = prev_node->next;
    }

    if (prev_node == NULL)
    {
        cout<<"\nNo previous node present so, element cann't be entered";
        return;
    }

    node *new_node = new node(item);
    new_node->data = item;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void insertlast(node **head, int item)
{
    node *new_node = new node(item);
    new_node->data = item;
    new_node->next = NULL;
    node *last = *head;
    if (*head == NULL)
    {
        *head = new_node;
        return;
    }

    while (last->next != NULL)
    {
        last = last->next;
    }

    last->next = new_node;
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

    while (del != NULL && del->data != item)
    {
        prevn = del;
        del = del->next;
    }

    if (del == NULL)
    {
        cout<<"\nElement no found\n";
        return;
    }

    prevn->next = del->next;
    free(del);
}

void printdll(node *head)
{
    node *ptr = head;
    printf("\n");
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
    int n, item, pos;
    char ch;
    cout<<"Do you want to enter elements in the Linked List(y or n):";
    cin>>ch;
    while (ch == 'y' || ch == 'Y')
    {
        cout<<"1.Insertion in front\n";
        cout<<"2.Insertion after a node\n";
        cout<<"3.Insertion at end\n";
        cout<<"4.Delete a Node\n";
        cout<<"5.Quit\n";
        cout<<"Enter your choice:";
    cin>>n;

        switch (n)
        {
        case 1:
            cout<<"Enter the data:";
            cin>>item;
            push(&head, item);
            break;
        case 2:
            cout<<"Enter the data:";
            cin>>item;
            cout<<"\nEnter the position after which you want to insert:";
            cin>>pos;
            insertafter(&head, item, pos);
            break;
        case 3:
            cout<<"Enter the data:";
            cin>>item;
            insertlast(&head, item);
            break;
        case 4:
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