class MyQueue {//implement queue with two stacks
public:
    stack<int> input,output;
    /** Initialize your data structure here. */
    MyQueue() {
        while(!input.empty()) input.pop();
        while(!output.empty()) output.pop();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(!output.empty()) {
            int res=output.top();
            output.pop();
            return res;
        }
        else {
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            int res=output.top();
            output.pop();
            return res;
        }
    }
    
    /** Get the front element. */
    int peek() {
        if(!output.empty()) return output.top();
        else{
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return output.empty()&&input.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */