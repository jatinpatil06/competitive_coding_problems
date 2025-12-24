// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node *curr = *head_ref, *lastValid = NULL;
        while(curr){
            Node *prev = curr -> prev, *next = curr -> next;
            if(curr -> data == x){
                //breaking off the current node
                if(next)    next -> prev = curr -> prev;
                if(prev)    prev -> next = next;
                delete(curr);
            }
            else    lastValid = curr;
            curr = next;
        }
        //moving to the new head
        if(!lastValid)  *head_ref = NULL;
        else{
            while(lastValid -> prev)    lastValid = lastValid -> prev;
            *head_ref = lastValid;
        }
    }
};