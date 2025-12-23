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
    int list_len(ListNode *head){
        ListNode *temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp -> next;
        }
        return len;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*  Brute force approach with TC = O(2N)
        int len = list_len(head);
        if(n == len)   return head -> next;
        ListNode *temp = head;
        for(int i = 1; i < len - n; i++)    temp = temp -> next;
        temp -> next = temp -> next -> next;
        return head;
            An optimal approach would be to do this in one pass.
        */
        ListNode *slow = head, *fast = head;
        while(n){
            fast = fast -> next;
            n--;
        }
        if(!fast)   return head -> next;
        while(fast -> next){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};