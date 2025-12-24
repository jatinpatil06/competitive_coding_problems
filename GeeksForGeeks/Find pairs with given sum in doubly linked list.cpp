// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        /*  Brute Force approach with TC = O(N ^ 2) & SC = O(1)
        vector<pair<int, int>> pairs;
        Node *i = head, *j;
        while(i){
            j = i -> next;
            while(j){
                if(i -> data + j -> data == target){
                    pairs.push_back({i -> data, j -> data});
                    break;
                }
                j = j -> next;
            }
            i = i -> next;
        }
        return pairs;
            
            Since the DLL is sorted, we can go for a two pointers approach with TC = O(N) & SC = O(1)
        */
        vector<pair<int, int>> answers;
        Node *left = head, *right = head;
        //move the right pointer to the last node
        while(right -> next != NULL)    right = right -> next;
        while(left != right){
            int sum = left -> data + right -> data;
            if(sum == target){
                answers.push_back({left -> data, right -> data});
                left = left -> next;
            }
            else if(sum > target)   right = right -> prev;
            else if(sum < target)   left = left -> next;
        }
        return answers;
    }
};