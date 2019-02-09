class Solution {
public:    
    struct cmp{
      bool operator() (const pair<int, string> a, const pair<int, string> b) {
          if(a.first == b.first) return a.second < b.second;
          return a.first > b.first;
      }  
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        // array & priority queue
        // time complexity: O(nlogk), space complexity: O(n)
        // 24ms, beats 78.57%
        
        // main idea:
        // only maintain priority queue with k words which has most frequency
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> max_k;
        unordered_map<string, int> counts;
        for(auto& word : words) {
            counts[word]++;
        }
        for(auto& iter : counts) {
            max_k.push({iter.second, iter.first});
            if(max_k.size() > k) max_k.pop();
        }
        int size = max_k.size();
        vector<string> res(size);
        for(int i = size - 1; i >= 0; i--) { 
            res[i] = max_k.top().second;
            max_k.pop();
        }
        // vector<int>.insert(vector<int>.begin(), max_k.top().second);
        // max_k.pop();
        return res;
    }
};