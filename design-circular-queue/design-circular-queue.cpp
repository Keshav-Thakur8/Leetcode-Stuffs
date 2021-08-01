class MyCircularQueue {
public:
    vector<int> q;
    int capacity;
    int curr_size;
    int front;
    int back;
    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k, -1);
        curr_size = 0;
        back = -1;
        front = 0;
    }
    
    bool enQueue(int value) {
        //oveflow check
        if(isFull()) {
            return false;
        }
        back = (back+1)%capacity;
        q[back] = value;
        curr_size++;
        return true;
    }
    
    bool deQueue() {
        //underflow check
        if(curr_size == 0) {
            return false;
        }
        front = (front+1)%capacity;
        curr_size--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) {
            return -1;
        }
        return q[front];
    }
    
    int Rear() {
        if(isEmpty()) {
            return -1;
        }
        return q[back];
    }
    
    bool isEmpty() {
        if(curr_size == 0) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(curr_size != capacity) {
            return false;
        }
        return true;
    }
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