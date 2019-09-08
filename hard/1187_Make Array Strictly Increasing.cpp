struct hash_pair {
    template<typename T, typename U>
    size_t operator()(const pair<T, U>& p) const {
        return hash<T>()(p.first) ^ hash<U>()(p.second);
    }
};

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // DFS with memo & DP
        // 652ms, beats 37.5%, need to be developed into DP!!
        
        // Main idea:
        // Use upper_bound to find least element which could replace current number.
        // 1. If arr1[i] <= last, then must switch: 
        //      1) If no one can switch, return abnormal number (3000 here)
        //      2) Enter switch branch
        // 2. If arr[1] > last, then can choose whether to switch, but:
        //      1) If no one can switch or switch number is bigger than current number, then no need to switch, enter no switch branch
        //      2) Else, enter both switch and no switch branch, and choose one with less operations
        // *We notice that in each round, only index `i` and last element `last` matters, so could use these two param to serve as memorization's key
        
        if(arr1.size() == 1) return 0;
        sort(arr2.begin(), arr2.end());
        int res = dfs(arr1, arr2, 0, -1);
        return res >= 3000 ? -1 : res;
    }
    
    int dfs(vector<int>& arr1, vector<int>& arr2, int i, int last) {
        if(i == arr1.size()) return 0;
        if(memo.count({i, last}) != 0) return memo[{i, last}];
        int res = 0;
        
        // Find element that cound be switched in arr2
        auto it = upper_bound(arr2.begin(), arr2.end(), last);
        
        if(arr1[i] <= last) {    // Must switch (if there is number can be switched)
            if(it == arr2.end()) res = 3000;
            else res = 1 + dfs(arr1, arr2, i + 1, *it);
        } else {                 // Can choose both 
            if(it == arr2.end() || *it >= arr1[i]) {    // No need to switch
                res = dfs(arr1, arr2, i + 1, arr1[i]);
            } else {
                res = min(dfs(arr1, arr2, i + 1, arr1[i]), 1 + dfs(arr1, arr2, i + 1, *it));    // Choose either one
            }
        }
        
        return memo[{i, last}] = res;
    }
private:
    unordered_map<pair<int, int>, int, hash_pair> memo;
};


// DP solution:
// time complexity: O(mn), space complexity: O(m)
// 92ms
const int INF = 1e9 + 7;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.resize(unique(arr2.begin(), arr2.end()) - arr2.begin());
        int N = arr1.size(), M = arr2.size();
        vector<int> pre(M + 1, 1);
        pre[M] = 0;
        for (int i = 1; i < N; ++i) {
            vector<int> curr(M + 1, INF);
            // not replacing
            if (arr1[i] > arr1[i-1]) curr[M] = pre[M];
            
            for (int j = 0; j < M; ++j) {
                // replace with arr2[j]
                if (arr2[j] > arr1[i-1]) curr[j] = min(curr[j], pre[M] + 1);
                // previous position replaced with arr2[j]
                if (arr2[j] < arr1[i]) curr[M] = min(curr[M], pre[j]);
            }
            int mi = INF;
            for (int j = 0; j < M; ++j) {
                curr[j] = min(curr[j], mi + 1);
                mi = min(mi, pre[j]);
            }
            pre = curr;
        }
        int ans = *min_element(pre.begin(), pre.end());
        return ans != INF ? ans : -1;
        
            
    }
};
