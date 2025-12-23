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
    ListNode *detectCycle(ListNode *head) {
        /*  Brute force approach, we store all the nodes, the moment we encounter an already visited node, we know the cycle started from there.
        unordered_map<ListNode*, int> visited;
        ListNode *temp = head;
        while(temp){
            if(visited.find(temp) != visited.end()) return temp;
            else    visited[temp] = 1;
            temp = temp -> next;
        }
        return NULL;

            An optimal approach would be to use the tortoise hare method with Sc = O(1)
            This can be done with Floyd's Cycle detection algorithm
                1) Detect cycle
                2) Find starting point if cycle exists
        */
        if(!head)   return head;
        //both pointers should start at head
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                //cycle found, move slow to head
                slow = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};