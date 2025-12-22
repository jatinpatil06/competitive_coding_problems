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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next)   return head;
        int len = list_len(head);
        k = k % len;
        if(k == 0)  return head;
        /*  Better approach with TC = O(N^2)
        k = k % list_len(head);
        for(int i = 0; i < k; i++){
            ListNode *prev = NULL, *temp = head;
            while(temp -> next){
                prev = temp;
                temp = temp -> next;
            }
            prev -> next = NULL;
            temp -> next = head;
            head = temp;
        }
            An optimal approach would be to find the kth element from the end and then concatenate it to the front with TC = O(N)
        */
        ListNode *temp = head;
        for(int i = 1; i < len - k; i++)    temp = temp -> next;
        ListNode *rotated = temp -> next;
        temp -> next = NULL;
        temp = rotated;
        while(temp -> next) temp = temp -> next;
        temp -> next = head;
        return rotated;
    }
};