/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    /*  No need to reverse since the list is already in reverse order
    ListNode *reverse(ListNode *head){
        ListNode *curr = head, *prev = NULL, *next = head -> next;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next)    next = next -> next;
        }
        return prev;
    }
    */
    // TC = O(max(m, n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL, *temp1 = l1, *temp2 = l2, *temp = head;
        int carry = 0;
        while(temp1 && temp2){
            int sum = temp1 -> val + temp2 -> val + carry;
            carry = sum / 10;
            sum %= 10;
            ListNode *nnode = new ListNode(sum);
            if(!head){
                head = nnode;
                temp = head;
            }
            else{
                temp -> next = nnode;
                temp = temp -> next;
            }    
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        //checking leftover nodes in first number
        while(temp1){
            int sum = temp1 -> val + carry;
            carry = sum / 10;
            sum %= 10;
            temp -> next = new ListNode(sum);
            temp = temp -> next;
            temp1 = temp1 -> next;
        }
        //checking leftover nodes in second number
        while(temp2){
            int sum = temp2 -> val + carry;
            carry = sum / 10;
            sum %= 10;
            temp -> next = new ListNode(sum);
            temp = temp -> next;
            temp2 = temp2 -> next;
        }
        //checking if any carry is left over
        if(carry){
            temp -> next = new ListNode(1);
            temp = temp -> next;
        }
        return head;
    }
};