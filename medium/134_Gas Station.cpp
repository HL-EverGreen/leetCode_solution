class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // array & greedy
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 100%
        
        // If total<0, no solution
        // Greedy: always leave minimum (gas[i] - cost[i]) step in last
        int total = 0, start, min_gas = INT_MAX;
        for(int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            if(total < min_gas) {
                min_gas = total;
                start = i + 1;
            }
        }
        return total < 0 ? -1 : start % gas.size();


        // force solution
        // time complexity: O(n^2)
        /*
        int remain_gas,g_size=gas.size(),c_size=cost.size(),index;
        if(g_size!=c_size) return -1;
        for(int i=0;i<gas.size();i++){
            int j=i,remain_gas=0;
            for(;j<i+g_size;j++){
                index=j%g_size;
                remain_gas+=gas[index]-cost[index];
                if(remain_gas<0) break;
            }
            if(j==i+g_size) return i; 
        }
        return -1;
        */
    }
};