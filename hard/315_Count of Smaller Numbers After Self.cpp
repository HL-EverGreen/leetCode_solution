class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // merge sort & array pair pattern
        // time complexity: O(nlogn), space complexity: O(n)
        // 36ms, beats 68.05%
        
        // Main idea:
        // Merge sort can help to solve find pair of i, j which nums[i] and nums[j] has some limitation (relation)

        // ***PLEASE MUST SEE BST SOLUTION BELOW!! VERY FAST

        int n = nums.size();
        vector<int> count(n, 0);
        vector<pair<int, int>> numsZip;     // Store nums value and its index
        for(int i = 0; i < n; ++i) numsZip.push_back({nums[i], i});
        sortAndCount(numsZip.begin(), numsZip.end(), count);
        return count;
    }

private:
    typedef vector<pair<int, int>>::iterator iter;
    
    /* Divide problem into two subproblems with start~mid and mid~end.
     * Calculate current inverse number of first half, and merge the first half and second half
    */
    void sortAndCount(iter start, iter end, vector<int>& count) {
        if(end - start <= 1) return;
        iter mid = start + (end - start) / 2;   // Middle iterator
        sortAndCount(start, mid, count);
        sortAndCount(mid, end, count);
        
        // Calculate inverse number in current loop for first halp elements
        for(iter i = start, j = mid; i < mid; ++i) {
            while(j < end && (*i).first > (*j).first) ++j;
            count[(*i).second] += j - mid;
        }
        // Merge these two parts in place
        inplace_merge(start, mid, end);
    }    
};


// BST version
// time complexity: O(nlogn), space complexity: O(n)
// 24ms, beats 97.48%

// Use node->dup and node->leftCount to handle duplicates and fast calculate number of nodes less than current node
// *Note: node->leftCount is not always correct actually, it only counts node inserted after the insertion of this node,
//        and in this way avoid protentially calculate duplicate nodes
class BSTNode {
public:
    int val;
    int dupCount;
    int leftCount;
    BSTNode* left;
    BSTNode* right;
    
    BSTNode(int x): val(x), dupCount(1), leftCount(0) {
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> counts(n, 0);
        if(n <= 1) return counts;
        
        BSTNode* root = new BSTNode(nums.back());
        
        for(int i = n - 2; i >= 0; --i) {
            BSTNode* cur = root;            // Compare from root
            int count = 0;
            int num = nums[i];
            while(true) {
                if(cur->val > num) {        // New node is less than current node
                    cur->leftCount++;
                    if(!cur->left) {
                        cur->left = new BSTNode(num);
                        break;
                    }
                    cur = cur->left;
                } else if(cur->val < num) { // New node is larger than current node
                    count += cur->leftCount + cur->dupCount;
                    if(!cur->right) {
                        cur->right = new BSTNode(num);
                        break;
                    }
                    cur = cur->right;
                } else {                    // New node is equal with current node
                    count += cur->leftCount;
                    cur->dupCount++;
                    break;
                }
            }
            counts[i] = count;
        }
        return counts;
    }   
};