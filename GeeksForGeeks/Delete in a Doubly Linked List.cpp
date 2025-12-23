/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    Node* delPos(Node* head, int x) {
        if(x == 1){
            head = head -> next;
            head -> prev = NULL;
            return head;
        }
        Node *curr = head, *prev = NULL, *next = NULL;
        for(int i = 1; i < x; i++)  curr = curr -> next;
        prev = curr -> prev;
        next = curr -> next;
        if(prev)    prev -> next = next;
        if(next)    next -> prev = prev;
        delete(curr);
        return head;
    }
};