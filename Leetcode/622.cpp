class MyCircularQueue {
public:
    MyCircularQueue(int k):queue(k + 1, 0){
        len = k + 1;
        start = 0;
        end = 0;
    }
    
    bool enQueue(int value) {
        if(isFull())
        {
            return false;
        }
        
        queue[end++] = value;
        end %= len;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        {
            return false;
        }
        
        start = (start + 1) % len;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : queue[start];
    }
    
    int Rear() {
        return isEmpty() ? -1 : queue[(end + len - 1) % len];
    }
    
    bool isEmpty() {
        return start == end;
    }
    
    bool isFull() {
        return (end + 1) % len == start;
    }
    
protected:
    vector<int> queue;
    int len;
    int start;
    int end;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */