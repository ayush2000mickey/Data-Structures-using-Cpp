#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    vector<node *> children;
};

void display(node *head)
{
    string str = "";
    str += head->data + "->";
    for (vector<node *>::iterator it = head->children.begin(); it != head->children.end(); it++)
    {
        str += (*it)->data + ",";
    }

    str += ".";
    cout << str;

    for (vector<node *>::iterator it = head->children.begin(); it != head->children.end(); it++)
    {
        display(*it);
    }
}

int main()
{
    int arr[] = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};

    node *root = NULL;

    stack<node *> st;
    int n = (sizeof(arr) / sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            node *t = new node;
            t->data = arr[i];

            if (st.size() > 0)
            {
                ((st.top())->children).push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }

    display(root);
    return 0;
}