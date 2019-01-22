class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        // array & greedy
        // time complexity: O(nlogn), space complexity: O(n)
        // 120ms, beats 94.04%
        
        // If B[i] is greater than all candidates in A, use the smallest one
        // Else use the smallest one but still greater than B[i]
        multiset<int> setA(A.begin(), A.end());
        for(int i = 0; i < B.size(); i++) {
            auto pos = *setA.rbegin() <= B[i] ? setA.begin() : setA.upper_bound(B[i]);          // setA.upper_bound(B[i]) is faster than upper_bound(setA.begin(), setA.end(), B[i])
            A[i] = *pos;
            setA.erase(pos);
        }
        return A;
    }
};