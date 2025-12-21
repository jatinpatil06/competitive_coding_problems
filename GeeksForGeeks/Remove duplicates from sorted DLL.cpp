/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        Node *curr = head;
        while(curr){
            Node *next = curr -> next;
            while(next != NULL && next -> data == curr -> data){
                Node *deletee_node = next;
                next = next -> next;
                delete(deletee_node);
            } 
            curr -> next = next;
            if(next != NULL)    next -> prev = curr;
            curr = next;
        }
        return head;
    }
};