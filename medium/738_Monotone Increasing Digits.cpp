class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        // string & greedy
        // time complexity: O(n), space complexity: O(1)
        // 4ms, beats 100%
        
        // track first i where num[i - 1] > num[i]
        // decrease num[i - 1] by 1 and set all following char to '9'
        string num = to_string(N);
        int marker = num.length();
        for(int i = num.length() - 1; i > 0; i--) {
            if(num[i - 1] > num[i]) {
                num[i - 1]--;
                marker = i;
            }
        }
        for(int i = marker; i < num.length(); i++) num[i] = '9';
        return stoi(num);             // stoi automatically remove begin '0'
    }
};