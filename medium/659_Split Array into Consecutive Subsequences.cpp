class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // array & greedy
        // time complexity: O(n), space complexity: O(n)
        // 104ms, beats 89.69%

        unordered_map<int, int> cnt, tail;
        for(auto num : nums) cnt[num]++;
        for(auto num : nums) {
            if(!cnt[num]) continue;
            cnt[num]--;
            if(tail[num - 1] > 0) {                         // combine with former sequence
                tail[num - 1]--;
                tail[num]++;
            } else if(cnt[num + 1] && cnt[num + 2]) {       // generate new sequence
                cnt[num + 1]--;
                cnt[num + 2]--;
                tail[num + 2]++;
            } else return false;                            // no match choice
        }
        return true;
    }
};