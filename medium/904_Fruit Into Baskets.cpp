class Solution {
public:
    int totalFruit(vector<int>& tree) {
        // two variable
        // time complexity: O(n), space complexity: O(1)
        // 132ms, beats 79.89%
        
        // num1: last second number appeared
        // num2: last number appeared
        // lastOneCount: last appeared number's count
        // cur: current total fruits' count
        int cur = 0, lastOneCount = 0, res = 0, num1 = tree[0], num2 = tree[0];
        for(int fruit : tree) {
            if(fruit == num2) {
                lastOneCount++;
                cur++;
            } else if(fruit == num1) {
                lastOneCount = 1;
                cur++;
                num1 = num2;
                num2 = fruit;
            } else {
                cur = lastOneCount + 1;
                lastOneCount = 1;
                num1 = num2;
                num2 = fruit;
            }
            res = max(res, cur);
        }
        return res;
        
        // use hash table
        // time complexity: O(n), space complexity: O(n)
        // 168ms, beats 51.27%
        /*
        int count = 0, start = 0, res = 0;
        unordered_map<int, int> fruit;
        for(int i = 0; i < tree.size(); i++) {
            if(++fruit[tree[i]] == 1) { count++; }
            while(count > 2) {
                if(--fruit[tree[start]] == 0) { count--; }
                start++;
            }
            res = max(res, i - start + 1);
        }
        return res;
        */
    }
};