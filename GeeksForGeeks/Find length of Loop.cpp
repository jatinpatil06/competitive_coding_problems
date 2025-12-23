/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        /*  Brute force approach with TC = O(NlogN) & SC = O(N)
        unordered_map<Node*, int> visited;
        Node *temp = head;
        while(temp){
            if(visited.find(temp) != visited.end()){
                //found a loop
                int len = 1;
                Node *start = temp;
                temp = temp -> next;
                while(temp != start){
                    len++;
                    temp = temp -> next;
                }
                return len;
            }
            else    visited[temp] = 1;
            temp = temp -> next;
        }
        return 0;
        
            An optimal approach would be to use Floyd's cycle detection algorithm
        */
        Node *slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                //cycle detected
                slow = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                //we now have the start of the cycle
                int len = 1;
                Node *start = slow;
                slow = slow -> next;
                while(slow != start){
                    len++;
                    slow = slow -> next;
                }
                return len;
            }
        }
        return 0;
    }
};