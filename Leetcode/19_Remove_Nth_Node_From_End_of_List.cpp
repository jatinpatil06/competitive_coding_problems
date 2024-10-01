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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> addrs;
        ListNode* temp = head;
        while(temp != NULL)
        {
            addrs.push_back(temp);
            temp = temp -> next;
        }
        int size = addrs.size();
        int k = size - n;
        if(k == 0)
            return head -> next;
        else if(k == size - 1)
            addrs[k - 1] -> next = NULL;
        else
            addrs[k - 1] -> next = addrs[k] -> next;
        return head;
    }
};