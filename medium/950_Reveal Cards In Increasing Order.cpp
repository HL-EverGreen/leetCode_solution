class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Array
        // time complexity: O(nlogn), space complexity: O(n)
        // 12ms, beats 95.79%
        
        // Main idea:
        // Use deque to simulate reverse progress
        deque<int> deq;
        int size = deck.size();
        sort(deck.rbegin(), deck.rend());   // Sort in decreasing order
        deq.push_back(deck[0]);
        
        for(int i = 1; i < size; i++) {
            deq.push_front(deq.back());
            deq.pop_back();
            deq.push_front(deck[i]);
        }
        return vector<int>(deq.begin(), deq.end());
    }
};