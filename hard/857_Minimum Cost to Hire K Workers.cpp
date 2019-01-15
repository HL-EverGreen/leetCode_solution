class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        // array
        // time complexity: O(NlogN), space complexity: O(n)
        // 40ms, beats 98.32%
        
        // Caculate all workers' wage/quality ratio and sort in ascending order, so if select worker[i] and worker[j] (i<j), min money need to pay is worker[j].ratio * (worker[i].qual + worker[j].qual)
        // And use priority queue dynamically keep K workers with least work quality while computing result continually
        int size = quality.size();
        vector<pair<double, int>> worker;   // wage/quality ratio, quality
        for(int i = 0; i < size; i++) {
            worker.push_back(make_pair(wage[i] * 1.0 / quality[i], quality[i]));
        }
        sort(worker.begin(), worker.end(), [](auto& a, auto& b) { return a.first < b.first; });
        
        int total_qual = 0;
        double res;
        priority_queue<int> work_qual;
        for(int i = 0; i < K; i++) {
            total_qual += worker[i].second;
            work_qual.push(worker[i].second);
        }
        res = total_qual * worker[K - 1].first;                 // calculate first K workers
        
        for(int i = K; i < size; i++) {                         // dynamically update group of workers with size K
            work_qual.push(worker[i].second);
            total_qual += worker[i].second;
            total_qual -= work_qual.top();
            work_qual.pop();
            res = min(res, total_qual * worker[i].first);
        }
        return res;
    }
};