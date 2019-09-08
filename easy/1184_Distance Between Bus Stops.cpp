class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        // array
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 100%
        
        int sum1 = 0;
        int sum2 = 0;
        int n = distance.size();
        if(destination < start) swap(start, destination);
        for(int i = 0; i < n; ++i) {
            if(i >= start && i < destination) sum1 += distance[i];
            else sum2 += distance[i];
        }
        return min(sum1, sum2);
    }
};