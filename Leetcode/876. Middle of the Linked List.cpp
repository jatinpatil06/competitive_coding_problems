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
    ListNode* middleNode(ListNode* head) {
        /*  Two pass approach
        int len = 0;
        ListNode *temp = head;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }
        temp = head;
        for(int i = 0; i < (len / 2); i++)  temp = temp -> next;
        return temp;

            We can find the middle node in one pass using the tortoise hare method
        */
        ListNode *slow = head, *fast = head -> next;
        while(fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
            if(fast != NULL)    fast = fast -> next;
        }
        return slow;
    }
};