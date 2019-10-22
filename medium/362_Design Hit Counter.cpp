// design & array
// time complexity: O(1) for hit and getHits, space complexity: O(1)
// 0ms, beats 100%

// Main idea:
// Use fixed-size (300) array to store hits for timestamp.
// Use another fixed-size array to store current timestamp occupies the index
// Calculate index through: timestamp % 300
// When getHits calls, iterate through all arrays and find index whose timestamp diff
// less than 300, and add those hits

class HitCounter {
public:
    /** Initialize your data structure here. */
    HitCounter() {
        hits.resize(300);
        time.resize(300);
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int index = timestamp % 300;
        if(time[index] != timestamp) {
            time[index] = timestamp;
            hits[index] = 1;
        } else ++hits[index];
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int hit = 0;
        for(int i = 0; i < 300; ++i) {
            if(timestamp - time[i] < 300) hit += hits[i];
        }
        return hit;
    }
private:
    vector<int> hits;
    vector<int> time;
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */