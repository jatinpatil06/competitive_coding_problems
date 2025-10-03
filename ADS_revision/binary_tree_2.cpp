#include<bits/stdc++.h>

//Defining the classes for the nodes and tree
class node{
    int val;
    node *left;
    node *right;
    public:
    node(){
        val = -1;
        left = NULL;
        right = NULL;
    }
    node(int val){
        this.val = val;
        left = NULL;
        right = NULL;
    }
    friend class binary_tree;
};

class binary_tree{
    private:
        node *root;
    public:
    binary_tree(){
        int value;
        cout << "Please enter a value for the root : ";
        cin >> value;
        root = new node(value);
    }

    void create_bt();
};

void binary_tree :: create_bt(){
    
}
int main()
{
    return 0;
}