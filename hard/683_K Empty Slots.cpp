class Solution {
public:
    int kEmptySlots(vector<int>& flowers, int k) {
        // array
        // time complexity: O(n), space complexity: O(n)
        // 184ms, beats 99%
        
        // days[i] means flower's bloom date which locates at position i + 1
        // so a solution satisfies: for every left < i < right, days[i] > days[left] && days[i] > days[right]
        vector<int> days(flowers.size());
        for(int i = 0; i < flowers.size(); i++) { days[flowers[i] - 1] = i + 1; }

        int left = 0, right = k + 1, res = flowers.size();
        for(int i = 0; right < flowers.size(); i++) {
            if(days[i] < days[left] || days[i] <= days[right]) {
                if(i == right) { res = min(res, max(days[left], days[right])); }        // if get a valid solution
                left = i;
                right = i + k + 1;                                                      // update new situation
            }
        }
        return res == flowers.size() ? -1 : res;
    }
};