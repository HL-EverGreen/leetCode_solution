class FreqStack {
public:
    FreqStack() {
        // design & stack
        // time complexity: O(1), space complexity: O(n)
        // 216ms, beats 98.20%
        
        // Main idea:
        // Use unordered_map to count each element's frequency.
        // Use different stacks with corresponding frequency to store element.
        // i.e. If 2 has freq of 3, then stacks with freq 1, 2, 3 all contains 2
        // Use max_freq to maintain current max frequency
        
        _max_freq = 0;
    }
    
    void push(int x) {
        _max_freq = max(_max_freq, ++_freq[x]);  // Update max_freq
        _freq_stack[_freq[x]].push(x);
    }
    
    int pop() {
        int ret = _freq_stack[_max_freq].top();
        _freq_stack[_max_freq].pop();                   // Pop from stack with current max freq
        --_freq[ret];
        if(_freq_stack[_max_freq].empty()) --_max_freq; // Decrease max_freq if current stack is empty
        return ret;
    }
private:
    unordered_map<int, int> _freq;              // Frequency of each element
    unordered_map<int, stack<int>> _freq_stack; // Stack with different frequency, store all numbers appear at certain frequency
    int _max_freq;                              // Maximum frequency up to now
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */