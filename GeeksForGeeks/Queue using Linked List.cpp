class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    int qu_size;
    Node *front, *rear;
  public:
    
    myQueue() {
        qu_size = 0;
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return qu_size == 0 ? 1 : 0;
    }

    void enqueue(int x) {
        Node *nnode = new Node(x);
        if(front == NULL){
            front = nnode;
            rear = nnode;
        } 
        else{
            rear -> next = nnode;
            rear = nnode;
        }
        qu_size++;
    }

    void dequeue() {
        if(front != NULL){
            front = front -> next;
            qu_size--;
        }   
    }

    int getFront() {
        if(front != NULL)   return front -> data;
        else    return -1;
    }

    int size() {
        return qu_size;
    }
};
