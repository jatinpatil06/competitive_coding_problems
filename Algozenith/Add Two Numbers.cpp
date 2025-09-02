
#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* n1, ListNode* n2) {
    ListNode* new_head = new ListNode(-1);
    ListNode *temp = new_head;
    bool carry = false;
    while(n1 && n2)
    {
        int value = n1 -> val + n2 -> val;
        if(carry)
        {
            value += 1;
            carry = false;
        }
        if(value >= 10)
        {
            value %= 10;
            carry = true;
        }
        ListNode *nnode = new ListNode(value);
        temp -> next = nnode;
        temp = temp -> next;
        n1 = n1 -> next;
        n2 = n2 -> next;
    }
    while(n1)
    {
        ListNode *nnode = new ListNode(n1 -> val);
        if(carry)
        {
            nnode -> val = nnode -> val + 1;
            carry = false;
        }
        if(nnode -> val >= 10)
        {
            nnode -> val %= 10;
            carry = true;
        }
        temp -> next = nnode;
        temp = temp -> next;
        n1 = n1 -> next;
    }

    while(n2)
    {
        ListNode *nnode = new ListNode(n2 -> val);
        if(carry)
        {
            nnode -> val = nnode -> val + 1;
            carry = false;
        }
        if(nnode -> val >= 10)
        {
            nnode -> val %= 10;
            carry = true;
        }
        temp -> next = nnode;
        temp = temp -> next;
        n2 = n2 -> next;
    }
    if(carry)
    {
        ListNode *nnode = new ListNode(1);
        temp -> next = nnode;
    }
    return new_head -> next;
}


ListNode* GetList(string &num) {
    ListNode* n1 = nullptr;
    ListNode* head = nullptr;
    for(int i = (int)num.length() - 1; i >= 0; i--) {
        ListNode* temp = new ListNode(num[i] - '0');
        if(n1) {
            n1->next = temp;
            n1 = temp;
        }
        else {
            n1 = temp;
            head = n1;
        }
    }
    return head;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string num1, num2;
    cin >> num1;
    cin >> num2;

    ListNode* n1 = GetList(num1);
    ListNode* n2 = GetList(num2);

    ListNode* sum = addTwoNumbers(n1, n2);

    string ans = "";
    while(sum) {
        ans += ('0' + sum->val);
        sum = sum->next;
    }

    reverse(ans.begin(), ans.end());

    cout << ans << "\n";

    return 0;
}
