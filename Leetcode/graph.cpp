#include<bits/stdc++.h>
using namespace std;
class gnode
{
    private:
    int vertex;
    gnode *next;
    friend class graph;
};

class graph
{
    private:
    int n;
    gnode* head[20];
    int visited[20];
    public:

    graph()
    {
        cout << "How many nodes do you want in the graph ? ";
        cin >> n;
        for(int i = 0 ; i < n; i++)
        {
            head[i] = new gnode;
            head[i] -> vertex = i;
            head[i] -> next = NULL;
        }
    }

    void create();
    void print_adj_list();
    void dfs_recursive();
    void dfs_recursive(int start);
    void dfs_non_recursive();
    void bfs();
};

void graph :: create()
{
    cout << "\nCreating the graph - > \n";
    for(int i = 0; i < n; i++)
    {
        gnode* temp = head[i];
        cout << "\nNODE " << i << "\n";
        cout << "Do you want to enter any adjacent nodes ? ";
        char ch;
        cin >> ch;
        while(ch == 'Y' || ch == 'y')
        {
            cout << "Enter name of adjacent node : ";
            int adj_node;
            cin >> adj_node;

            if(adj_node == head[i] -> vertex)
                cout << "Self loops are not allowed!\n";
            else
            {
                gnode* nnode = new gnode;
                nnode -> vertex = adj_node;
                nnode -> next = NULL;
                temp -> next = nnode;
                temp = temp -> next;
                cout << "Do you want to enter any adjacent nodes ? ";
                cin >> ch;
            }
        }
    }
}

void graph :: print_adj_list()
{
    cout << "\nADJACENCY LIST\n";
    for(int i = 0; i < n; i++)
    {
        cout << head[i] -> vertex << " -> ";
        gnode* temp = head[i] -> next;
        while(temp != NULL)
        {
            cout << temp -> vertex << ", ";
            temp = temp -> next;
        }
        cout << "\n";
    }
}

void graph :: dfs_recursive()
{
    cout << "\nDepth First Traversal Recursive\n";
    //first we'll mark all the vertices as unvisited
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    //accept the startting vertex
    int start;
    cout << "What node do you want to start from ? ";
    cin >> start;
    dfs_recursive(start);
}

void graph :: dfs_recursive(int v)
{
    //marking this vertex as visited
    visited[v] = 1; 
    cout << head[v] -> vertex << " ";

    //now we will call the same function for all its adjacent nodes
    gnode *temp = head[v] -> next;
    while(temp != NULL)
    {
        if(visited[temp -> vertex] != 1)
            dfs_recursive(temp -> vertex);
        temp = temp -> next;
    }
}

void graph :: dfs_non_recursive()
{
    cout << "\nDepth First Traversal Non-Recursive\n";
    //first we'll mark all the vertices as unvisited
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    //accept the startting vertex
    int start;
    cout << "What node do you want to start from ? ";
    cin >> start;

    //creating a stack to keep track of the vertices to be explored
    stack<int> st;
    st.push(start);
    visited[start] = 1;
    while(!st.empty())
    {
        gnode *temp = head[st.top()];
        st.pop();
        cout << temp -> vertex << " ";
        //for all the adjacent vertices
        temp = temp -> next;
        while(temp != NULL)
        {
            if(visited[temp -> vertex] != 1)
            {
                st.push(temp -> vertex);
                visited[temp -> vertex] = 1;
            }
            temp = temp -> next;
        }
    }
}

void graph :: bfs()
{
    cout << "\nBreadth First Traversal\n";
    //first we'll mark all the vertices as unvisited
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    //accept the startting vertex
    int start;
    cout << "What node do you want to start from ? ";
    cin >> start;

    //we'll use a queue to keep track of the nodes visited so far
    queue<int> qu;
    qu.push(start);
    visited[start] = 1;
    while(!qu.empty())
    {
        gnode *temp = head[qu.front()];
        qu.pop();
        cout << temp -> vertex << " ";

        //for all nodes adjacent to temp
        temp = temp -> next;
        while(temp != NULL)
        {
            if(visited[temp -> vertex] != 1)
            {
                qu.push(temp -> vertex);
                visited[temp -> vertex] = 1;
            }
            temp = temp -> next;
        }
    }
}
int main()
{
    graph g1;
    g1.create();
    g1.print_adj_list();
    g1.dfs_recursive();
    g1.dfs_non_recursive();
    g1.bfs();
    return 0;
}