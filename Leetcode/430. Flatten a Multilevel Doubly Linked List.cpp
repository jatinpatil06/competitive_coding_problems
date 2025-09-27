/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* traverse(Node *address, Node* prev)
    {
        if(address == NULL) return NULL;
        Node *temp = address;
        address -> prev = prev;
        while(temp != NULL)
        {
            if(temp -> child != NULL)
            {
                Node *container = temp -> next;
                temp -> next = traverse(temp -> child, temp);
                temp -> child = NULL;
                while(temp -> next != NULL) temp = temp -> next;
                temp -> next = container;
                if(container != NULL)   container -> prev = temp;
            }
            temp = temp -> next;
        }
        return address;
    }
    Node* flatten(Node* head) {
        return traverse(head, NULL);
    }
};