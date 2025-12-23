/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        /*  Brute Force approach with TC = O(N) & SC = O(N)
            We maintain a visited array, if we encounter any node we have visited before, we have found a cycle.
        ListNode *temp = head;
        unordered_map<ListNode*, int> visited;
        while(temp){
            if(visited.find(temp) != visited.end()) return true;
            else    visited[temp] = 1;
            temp = temp -> next;
        }
        return false;

            An optimal approach would be to use the tortoise hare method, with TC = O(N) & SC = O(1)
            We use one fast pointer and one slow pointer, if they catch up, there exists a cycle.
            If the fast pointer reaches the end, that means there exists no cycle.
        */
        if(!head)   return false;
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next){
            //move them first, since initially slow = fast = head
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast)    return true;
        }
        return false;
    }
};