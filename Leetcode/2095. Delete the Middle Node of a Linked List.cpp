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
    ListNode* deleteMiddle(ListNode* head) {
        vector <ListNode*> nodes;
        ListNode* temp = head;
        while(temp != NULL)
        {
            nodes.push_back(temp);
            temp = temp -> next;
        }
        int middle = nodes.size() / 2;
        if(middle == 0)
            head = head -> next;
        else if(middle == nodes.size() - 1)
            nodes[middle - 1] -> next = NULL;
        else
            nodes[middle - 1] -> next = nodes[middle] -> next;
        return head;

        /*
            Single Pass deletion
            if(head -> next == NULL)    return NULL;
            ListNode *prev = head, *slow = head, *fast = head -> next;
            while(fast != NULL){
                prev = slow;
                slow = slow -> next;
                fast = fast -> next;
                if(fast)    fast = fast -> next;
            }
            prev -> next = slow -> next;
            return head;
        */
    }
};