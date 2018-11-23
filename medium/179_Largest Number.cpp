class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // string
        // time complexity: O(nlogn)
        // convert all integer into string and sort them by (s1 + s2 > s2 + s1)
        // then add them in order
        
        vector<string> str_array;
        string res;
        
        //convert to string stored in vector
        for(int num:nums){
            str_array.push_back(to_string(num));
        }
        
        //sort by s1 + s2 > s2 + s1
        sort(str_array.begin(), str_array.end(), [](string& s1, string& s2){return s1 + s2 > s2 + s1;});
        
        //combine result
        for(auto str:str_array){
            res += str;
        }
        
        //check 0 in the first position
        while(res[0] == '0' && res.length() > 1){
            res.erase(0, 1);
        }
        return res;
    }
};