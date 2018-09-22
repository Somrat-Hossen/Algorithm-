#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int roll;
    node * next;
};

node *root=NULL;

void push(int item)
{
    if(root==NULL) ///If the list is empty
    {
        root=new node();
        root->roll=item;
        root->next=NULL;
    }
    else
    {
        node *cur_node=root;          ///make a copy of root node
        while(cur_node->next!=NULL)   ///find the last node
        {
            cur_node=cur_node->next;   ///go to the next address
        }

        node *new_node=new node();        ///create a new node
        new_node->roll=item;
        new_node->next=NULL;

       cur_node->next=new_node;        ///link the last node with new node
    }
}

void show()
{
    puts("Element are in the list:");
    node * cur_node=root;

    while(cur_node!=NULL)  ///loop until you reach null point
    {
        cout<<(cur_node->roll)<<" ";
        cur_node=cur_node->next;
    }
}

int main()
{

  push(5);
  push(15);
  push(25);
  push(35);
  push(45);
  push(55);

  show();
    return 0;
}
