class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        // string
        // time complexity: O(n), space complexity: O(1)
        // 0ms, beats 100%
        
        // Main idea:
        // Straight forward. Can refer to solution 2 which uses stringstream.
        pair<int, int> paraA = parse(a), paraB = parse(b);
        return to_string(paraA.first * paraB.first - paraA.second * paraB.second) + "+" +
            to_string(paraA.first * paraB.second + paraA.second * paraB.first) + "i";
    }
    
    // Parse input string and get parameter
    pair<int, int> parse(string a) {
        int plusIdx = a.find('+'), iIdx = a.find('i');
        return {stoi(a.substr(0, plusIdx)), stoi(a.substr(plusIdx + 1, iIdx - plusIdx - 1))};
    }
    
    
    // Solution 2:
    // Using stringsteam can easily extract number from string
    /*
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;                          // Notice the using of char
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
    */
};
