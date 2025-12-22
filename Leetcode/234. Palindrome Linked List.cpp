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
    bool isPalindrome(ListNode* head) {
        /*  Brute Force approach with TC = O(N) && SC = O(N)
        vector<int> v;
        ListNode *temp = head;
        while(temp){
            v.push_back(temp -> val);
            temp = temp -> next;
        }
        int l = 0, r = v.size() - 1;
        while(l <= r){
            if(v[l] != v[r])    return false;
            l++;
            r--;
        }
        return true;
            An optimal approach would be to have TC = O(N) && SC = (1)
        */
        if(head -> next == NULL)    return head;
        //finding the middle of the linked list
        ListNode *prev, *slow = head, *fast = head -> next;
        while(fast){
            prev = slow;
            slow = slow -> next;
            fast = fast -> next;
            if(fast)    fast = fast -> next;
        }
        //reversing the second half
        prev = NULL;
        ListNode *curr = slow, *next = curr -> next;
        while(curr){
            curr -> next = prev;
            prev = curr;
            curr = next;
            if(next)    next = next -> next;
        }
        //now we will chech for palindrome
        ListNode *temp1 = head, *temp2 = prev;
        while(temp1 && temp2){
            if(temp1 -> val != temp2 -> val)    return false;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        return true;
    }
};