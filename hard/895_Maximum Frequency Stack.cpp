class FreqStack {
public:
    // frequency stack
    // time complexity: O(1), space complexity: O(n)
    // 256ms, beats 100%
    
    // main idea:
    // max_freq: max frequency of all numbers
    // unordered_map<int, int> freq: certain number's frequency
    // unordered_map<int, stack<int>> m: store all numbers appear at certain frequency
    FreqStack(): max_freq(0) {
        
    }
    
    void push(int x) {
        max_freq = max(max_freq, ++freq[x]);        // update max_freq
        m[freq[x]].push(x);                         // insert x in corresponding stack
    }
    
    int pop() {
        int x = m[max_freq].top();
        m[max_freq].pop();
        if(!m[freq[x]--].size()) max_freq--;        // if no other number reaches max_freq, max_freq--
        return x;
    }
private:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> m;
    int max_freq;
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */