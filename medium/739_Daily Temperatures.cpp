class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // stack
        // time complexity: O(n), space complexity: O(n)
        // 220ms, beats 82.93%
        // main idea: 
        // 1. push element from the end of arrays in each round
        // 2. in each round, if stack.top() is lower, pop, until find the first greater element or stack is empty (no warmer day)
        
        int size = T.size();
        if(size == 0) return {};
        vector<int> res(size, 0);
        stack<int> day;
        for(int i = size - 1; i >= 0; i--) {
            while(!day.empty() && T[i] >= T[day.top()]) day.pop();
            if(!day.empty()) res[i] = day.top() - i;
            day.push(i);
        }
        return res;

        // int size = T.size();
        // vector<int> res(size, 0);
        // stack<pair<int, int>> day;
        // day.push({T[size - 1], size - 1});
        // for(int i = size - 2; i >= 0; i--) {
        //     if(T[i] < day.top().first) res[i] = day.top().second - i;
        //     while(!day.empty() && T[i] >= day.top().first) day.pop();           // pop lower temperature days
        //     if(!day.empty()) res[i] = day.top().second - i;
        //     day.push({T[i], i});
        // }
        // return res;
        
        // a nearly O(n) time and O(1) space solution
        /*
        vector<int> res(temperatures.size());
        for (int i = temperatures.size() - 1; i >= 0; --i) {
            int j = i+1;
            while (j < temperatures.size() && temperatures[j] <= temperatures[i]) {
                if (res[j] > 0) j = res[j] + j;
                else j = temperatures.size();
            }
            // either j == size || temperatures[j] > temperatures[i]
            if (j < temperatures.size()) res[i] = j - i;
        }
        return res;
        */
    }
};