/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node *reverse_list(Node *head){
        Node *prev = NULL, *curr = head, *next = head -> next;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next)    next = next -> next;
        }
        return prev;
    }
    
    Node *add_one(Node *head){
        Node *temp = head;
        int carry = 1;
        while(carry && temp){
            int sum = temp -> data + carry;
            carry = sum / 10;
            temp -> data = sum % 10;
            if(carry && !temp -> next){
                Node *nnode = new Node(1);
                temp -> next = nnode;
                carry = 0;
            }
            temp = temp -> next;
        }
        return head;
    }
    
    Node* addOne(Node* head) {
        Node *rev_head = reverse_list(head);
        Node *added_one = add_one(rev_head);
        head = reverse_list(added_one);
        return head;
    }
};