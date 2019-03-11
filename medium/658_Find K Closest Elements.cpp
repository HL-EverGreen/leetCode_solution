class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // binary search
        // time complexity: O(logn), space complexity: O(1)
        // 100ms, beats 99.15%
        
        // main idea:
        // If x - arr[mid] > arr[mid + k] - x, means that arr[mid + 1] ~ arr[mid + k] is better than arr[mid] ~ arr[mid + k - 1]
        
        int left = 0, right = arr.size() - k;
        
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(x - arr[mid] > arr[mid + k] - x) left = mid + 1;
            else right = mid;                                                   // include ==, because small number is preferred
        }
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};