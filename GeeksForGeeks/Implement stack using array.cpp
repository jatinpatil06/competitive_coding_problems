class myStack {
  public:
    int top, n;
    int *arr;
    myStack(int n) {
        this -> n = n;
        top = -1;
        arr = new int[n];
    }

    bool isEmpty() {
        return top == -1 ? true : false;
    }

    bool isFull() {
        return top == n - 1 ? true : false;
    }

    void push(int x) {
        if(!isFull())   arr[++top] = x;
    }

    void pop() {
        if(!isEmpty())  top--;
    }

    int peek() {
        if(!isEmpty())  return arr[top];
        return -1;
    }
};