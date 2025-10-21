/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {
    Node *prev, *curr;
    int st_size;
  public:
    myStack() {
        prev = NULL;
        curr = NULL;
        st_size = 0;
    }

    bool isEmpty() {
        return curr == NULL ? true : false;
    }

    void push(int x) {
        Node *nnode = new Node(x);
        nnode -> next = curr;
        curr = nnode;
        st_size++;
    }

    void pop() {
        if(!isEmpty()){
            curr = curr -> next;
            st_size--;
        }
    }

    int peek() {
        if(!isEmpty())  return curr -> data;
        return -1;
    }

    int size() {
        return st_size;
    }
};