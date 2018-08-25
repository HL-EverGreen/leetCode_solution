class MinStack { //stack
public:
    /** initialize your data structure here. */
    
    //can also use stack<pair<int,int>> mySta;
    vector<int> minStack;
    vector<int> minElem;
    MinStack() {
        
    }
    
    void push(int x) {
        minStack.push_back(x);
        if(minStack.size()==1) minElem.push_back(x);
        else minElem.push_back(min(minElem.back(),x));
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
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */