#include <bits/stdc++.h>
using namespace std;
// Defining the classes
class node
{
    char val;
    node *next;

public:
    node(char val)
    {
        this->val = val;
        next = NULL;
    }
    friend class linked_list;
};

class linked_list
{
private:
    node *head;

public:
    linked_list()
    {
        char val;
        cout << "Please enter the value for the head of the linked list : ";
        cin >> val;
        head = new node(val);
    }
    int length();
    void print_list();
    void insert_nodes();
    void delete_node(int pos);
    void search_element(int val);
};

int linked_list :: length()
{
    node *temp = head;
    int count = 0;
    while(temp != NULL)
    {
        count++;
        temp = temp -> next;
    }
    return count;
}

void linked_list ::print_list()
{
    cout << "Printing the Linked List : \n";
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void linked_list ::insert_nodes()
{
    while (true)
    {
        char choice;
        cout << "Where do you want to add nodes?\ns - start\ne - end\ni - any location\nno further nodes need to be added - n\n";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
            break;

        char val;
        cout << "Please enter the value for the new node : ";
        cin >> val;
        node *nnode = new node(val);

        if (choice == 's')
        {
            nnode->next = head;
            head = nnode;
        }
        else if (choice == 'e')
        {
            node *temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = nnode;
        }
        else if (choice == 'i')
        {
            int pos;
            cout << "What position do you want to add a node at ? ";
            cin >> pos;
            if (pos == 1)
            {
                nnode->next = head;
                head = nnode;
            }
            else
            {
                node *temp = head;
                for (int i = 1; i < pos - 1; i++)
                    temp = temp->next;
                nnode->next = temp->next;
                temp->next = nnode;
            }
        }
    }
}
void linked_list ::search_element(int val)
{
    node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        if (temp->val == val)
        {
            cout << "Element found at position - " << i << " !\n";
            break;
        }
        temp = temp->next;
        i++;
    }
}

void linked_list :: delete_node(int pos)
{
    if(pos > length())  cout << "No node exists at given position!\n";
    else if(pos == 1)
    {
        node *to_be_deleted = head;
        head = head -> next;
        to_be_deleted -> next = NULL;
        delete to_be_deleted;
    }
    else
    {
        node *temp = head;
        for(int i = 1; i < pos - 1; i++)    temp = temp -> next;
        node * to_be_deleted = temp -> next;
        temp -> next = temp -> next -> next;
        to_be_deleted -> next = NULL;
        delete to_be_deleted;
    }
}

int main()
{
    linked_list list1;
    list1.insert_nodes();
    list1.print_list();
    return 0;
}