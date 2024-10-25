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
    int pairSum(ListNode* head) {
        int twinSum = 0;
        vector <int> node_vals;
        ListNode* temp = head;
        while(temp != NULL)
        {
            node_vals.push_back(temp -> val);
            temp = temp -> next;
        }
        int n = node_vals.size();
        for(int i = 0; i < n/2; i++)
            twinSum = max(twinSum, node_vals[i] + node_vals[n-1-i]);
        return twinSum;
    }
};