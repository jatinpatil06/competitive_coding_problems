#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class treenode
{
    char val;
    treenode *left;
    treenode *right;
    public:
    treenode()
    {
        left = NULL;
        right = NULL;
    }
    friend class tree;
};

class tree
{
    treenode *root;
    public:
    tree()
    {
        root = NULL;
    }
    void create_tree();
    void inorder_r();
    void inorder_r(treenode *temp);
    void preorder_r();
    void preorder_r(treenode *temp);
    void postorder_r();
    void postorder_r(treenode *temp);

    void inorder();
    void preorder();
    void postorder();

    void level_search();
};

void tree :: create_tree()
{
    if(root == NULL)
    {
        root = new treenode;
        cout << "Enter the value for the root node : ";
        cin >> root -> val;
        root -> left = NULL;
        root -> right = NULL;
    }

    char ch;
    cout << "Do you want to add another node? ";
    cin >> ch;
    while(ch == 'y' || ch == 'Y')
    {
        treenode *temp = root;
        treenode *nnode = new treenode;
        cout << "Enter the value for the new node : ";
        cin >> nnode -> val;
        nnode -> left = NULL;
        nnode -> right = NULL;
        
        bool flag = false;
        while(flag == false)
        {
            char side;
            cout << "Do you want to attach to the left or right? ";
            cin >> side;
            if(side == 'l' || side == 'L')
            {
                if(temp -> left == NULL)
                {
                    temp -> left = nnode;
                    flag = true;
                    cout << "Successfully added node to left side." << endl;
                    break;
                }
                temp = temp -> left;
            }
            if(side == 'r' || side == 'R')
            {
                if(temp -> right == NULL)
                {
                    temp -> right = nnode;
                    flag = true;
                    cout << "Successfully added node to right side." << endl;
                    break;
                }
                temp = temp -> right;
            }
        }
        cout << "Do you want to add another node? ";
        cin >> ch;
    }
}

void tree :: inorder_r()
{
    if(root != NULL)
    {
        cout << "Inorder Tree Traversal" << endl;
        inorder_r(root);
    }
    else
        cout << "Root is NULL." << endl;
}
void tree :: inorder_r(treenode *temp)
{
    if(temp != NULL)
    {
        inorder_r(temp -> left);
        cout << temp -> val << " ";
        inorder_r(temp -> right);
    }
}

void tree :: preorder_r()
{
    if(root != NULL)
    {
        cout << "Preorder Tree Traversal" << endl;
        preorder_r(root);
    }
    else
        cout << "Root is NULL." << endl;
}
void tree :: preorder_r(treenode *temp)
{
    if(temp != NULL)
    {
        cout << temp -> val << " ";
        preorder_r(temp -> left);
        preorder_r(temp -> right);
    }
}

void tree :: postorder_r()
{
    if(root != NULL)
    {
        cout << "Postorder Tree Traversal" << endl;
        postorder_r(root);
    }
    else
        cout << "Root is NULL." << endl;
}
void tree :: postorder_r(treenode *temp)
{
    if(temp != NULL)
    {
        postorder_r(temp -> left);
        postorder_r(temp -> right);
        cout << temp -> val << " ";
    }
}

void tree :: level_search()
{
    cout << "Level wise search " << endl;
    queue <treenode*> qu;
    if(root != NULL)
        qu.push(root);
    while(!qu.empty())
    {
        treenode *temp = qu.front();
        qu.pop();
        cout << temp -> val << " ";
        if(temp -> left != NULL)
            qu.push(temp -> left);
        if(temp -> right != NULL)
            qu.push(temp -> right);
    }
}

void tree :: inorder()
{
    cout << "Inorder Traversal (Iterative)" << endl;
    stack <treenode*> st;
    treenode *temp = root;
    while(1)
    {
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp -> left;
        }
        if(st.empty())
            break;
        temp = st.top();
        st.pop();
        cout << temp -> val << " ";
        temp = temp -> right;
    }
}

void tree :: preorder()
{
    cout << "Preorder Traversal (Iterative)" << endl;
    stack <treenode*> st;
    treenode *temp = root;
    while(1)
    {
        while(temp != NULL)
        {
            cout << temp -> val << " ";
            st.push(temp);
            temp = temp -> left;
        }
        if(st.empty())
            break;
        temp = st.top();
        st.pop();
        temp = temp -> right;
    }
}

void tree :: postorder()
{
    cout << "Postorder Traversal (Iterative)" << endl;
    stack <treenode*> st;
    treenode *temp = root;
    while(1)
    {
        while(temp != NULL)
        {
            st.push(temp);
            temp = temp -> left;
        }
        if(st.top() -> right == NULL)
        {
            temp = st.top();
            st.pop();
            cout << temp -> val << " ";
        }
        while(!st.empty() && st.top() -> right == temp)
        {
            temp = st.top();
            st.pop();
            cout << temp -> val << " ";
        }
        if(st.empty())
            break;
        temp = st.top() -> right;
    }
}
int main()
{
    tree t1;
    t1.create_tree();
    t1.inorder_r();
    t1.preorder_r();
    t1.postorder_r();
    t1.level_search();
    t1.inorder();
    t1.preorder();
    t1.postorder();
    return 0;
}