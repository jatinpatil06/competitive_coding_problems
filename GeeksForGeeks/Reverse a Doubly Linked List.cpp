/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node *curr = head, *prev = curr -> prev, *next = curr -> next;
        while(curr){
            swap(curr -> next, curr -> prev);
            prev = curr;
            curr = curr -> prev;
        }
        return prev;
    }
};