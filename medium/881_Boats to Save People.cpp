class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // array & greedy
        // time complexity: O(n), space complexity: O(1)
        // 80ms, beats 69.96%
        
        sort(people.begin(), people.end());
        int boat = 0;
        for(auto i = people.begin(), j = people.end() - 1; i <= j; boat++, j--) {
            if(*i + *j <= limit) i++;
        }
        return boat;
    }
};