// design
// time complexity: O(1), space complexity: O(n)
// 88ms, beats 92.04%

class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        // If this message isn't new and has been printed in last 10 seconds
        if(m.count(message) && m[message] > timestamp - 10) {
            return false;
        } else {
            m[message] = timestamp;
            return true;
        }
    }
private:
    unordered_map<string, int> m;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */