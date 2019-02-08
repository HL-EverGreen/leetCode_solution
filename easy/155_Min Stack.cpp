class MinStack {
public:
    /** initialize your data structure here. */

    // stack
    // push/pop/top/getMin time complexity: O(1)
    // 16ms, beats 99%

    // main idea: use another vector minElem to record each minimal value at every stack's status
    MinStack() {

    }
    
    void push(int x) {
        minStack.push_back(x);
        if(minStack.size() == 1) minElem.push_back(x);
        else minElem.push_back(min(minElem.back(), x));
    }
    
    void pop() {
        minStack.pop_back();
        minElem.pop_back();
    }
    
    int top() {
        return minStack.back();
    }
    
    int getMin() {
        return minElem.back();
    }
private:
    vector<int> minStack;
    vector<int> minElem;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */