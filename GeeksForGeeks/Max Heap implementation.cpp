class maxHeap {
  private:
    vector<int> v;
    int k;

  public:
    maxHeap(){
        k = 0;
        v.reserve(1e6);
    }
    
    void push(int x) {
        v[k] = x;
        reheapUp(k);
        k++;
    }

    void pop() {
        if(k != 0){
            swap(v[0], v[k - 1]);
            k--;
            reheapDown(0);
        }
    }

    int peek() {
        return k == 0 ? -1 : v[0];
    }

    int size() {
        return k;
    }
    
    //iterative version
    void reheapUp(int i){
        while(i > 0){
            int parent = (i - 1) / 2;
            if(v[parent] >= v[i])   break;
            swap(v[parent], v[i]);
            i = parent;
        }
    }

    //recursive version
    void reheapUp(int i){
        if(i == 0)  return;
        int parent = (i - 1) / 2;
        if(v[parent] < v[i]){
            swap(v[parent], v[i]);
            reheapUp(parent);
        }
    }
    
    //iterative version
    void reheapDown(int i){
        while(true){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;
            if(left < k && v[left] > v[largest])    largest = left;
            if(right < k && v[right] > v[largest])  largest = right;
            if(largest == i)    break;
            swap(v[largest], v[i]);
            i = largest;
        }
    }

    //recursive version
    void reheapDown(int i){
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;
        if(left < k && v[left] > v[largest])    largest = left;
        if(right < k && v[right] > v[largest])  largest = right;
        if(largest != i){
            swap(v[largest], v[i]);
            reheapDown(largest);
        }
    }
};