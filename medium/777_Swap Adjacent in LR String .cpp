class Solution {
public:
    bool canTransform(string start, string end) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 8ms, beats 99.13%
        
        // first check number of 'R' and 'L' is the same
        // then if the order of any two of 'R' and 'L' in start and end is different, return false, since transform can't change position of 'R' and 'L'
        // if start[i] == 'R' and i > j, return false, since R can only move forward
        // if start[i] == 'L' and i < j, return false, since L can only move backword

        int size = start.size(), r_cnt = 0, l_cnt = 0;

        for(int i = 0; i < size; i++) {
            if(start[i] == 'R') { r_cnt++; }
            else if(start[i] == 'L') { l_cnt++; }
            if(end[i] == 'R') { r_cnt--; }
            else if(end[i] == 'L') { l_cnt--; }
        }
        if(r_cnt != 0 || l_cnt != 0) { return false; }              // check number of 'L' and 'R'
        
        for(int i = 0, j = 0; i < size && j < size; i++, j++) {
            while(i < size && start[i] == 'X') { i++; }
            while(j < size && end[j] == 'X') { j++; }
            if(i == size && j == size) { return true; }
            if(i == size || j == size || start[i] != end[j]) { return false; }
            if(start[i] == 'R' && i > j) { return false; }
            if(start[i] == 'L' && i < j) { return false; }
        }
        return true;
    }
};