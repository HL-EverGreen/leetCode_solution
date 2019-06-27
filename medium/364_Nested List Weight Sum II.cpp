/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        // dfs & array
        // space complexity: O(n) + stack memory
        // 0ms, beats 100%
        
        // Main idea:
        // Use `mem` to store sum of numbers in each depth.
        // Use DFS to generate `mem`.
        
        vector<int> mem;
        /* Get sum grouped by depth */
        group(nestedList, mem, 0);
        
        /* Calculate res */
        int size = mem.size(), res = 0;
        for(int i = 0; i < size; i++) {
            res += mem[i] * (size - i);
        }
        return res;
    }
    
    /* Do DFS to current nestlist and populate `mem` */
    void group(vector<NestedInteger>& nl, vector<int>& mem, int depth) {
        for(auto elem : nl) {
            if(elem.isInteger()) {                 // int
                while(mem.size() <= depth) {       // Populate `mem` if necessary
                    mem.push_back(0);
                }
                mem[depth] += elem.getInteger();
            } else {                               // NestedList 
                group(elem.getList(), mem, depth + 1);
            }
        }
    }
};