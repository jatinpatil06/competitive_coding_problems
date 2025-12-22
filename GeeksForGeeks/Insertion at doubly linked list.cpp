/*
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node *insertAtPos(Node *head, int p, int x) {
        Node *temp = head;
        for(int i = 0; i < p; i++)  temp = temp -> next;
        Node *nnode = new Node(x);
        nnode -> next = temp -> next;
        nnode -> prev = temp;
        if(temp -> next)    temp -> next -> prev = nnode;
        temp -> next = nnode;
        return head;
    }
};