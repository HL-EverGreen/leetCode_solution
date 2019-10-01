// design
// 36ms, beats 80.27%

// Main idea:
// Use front and rear to represent next available position that new value can be inserted.
// So in initialization, set front to 1 and set rear to 0.

class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): cnt(0), size(k), front(1), rear(0) {
        db.resize(k, 0);
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(cnt == size) return false;
        db[front] = value;
        front = (front + 1) % size;
        ++cnt;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(cnt == size) return false;
        db[rear] = value;
        rear = (rear + size - 1) % size;
        ++cnt;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(cnt == 0) return false;
        front = (front + size - 1) % size;
        --cnt;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(cnt == 0) return false;
        rear = (rear + 1) % size;
        --cnt;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if(cnt == 0) return -1;
        return db[(front + size - 1) % size];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if(cnt == 0) return -1;
        return db[(rear + 1) % size];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return cnt == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cnt == size;
    }
private:
    int front;  // Next available position to insert new element at front
    int rear;   // Same but insert at back
    int cnt;    // Number of current elements
    int size;   // Capacity
    vector<int> db;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */