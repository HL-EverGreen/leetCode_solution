class Solution {
public:
    string countAndSay(int n) {
        //use static vector save running time from 4ms to 0ms(18 test cases)
        if (n == 0) return "";
        static vector<string> res({"1"});
        int num=n-res.size()+1,tmp=res.size()-1;
        while ((--num)>0) {
            string cur = "";
            int size=res[tmp].size();
            for (int i = 0; i < size; i++) {
                int count = 1;
                while ((i + 1 < size && (res[tmp][i] == res[tmp][i + 1]))){
                    count++;    
                    i++;
                }
                cur += to_string(count) + res[tmp][i];
            }
            res.push_back(cur);
            tmp++;
        }
        return res[n-1];
    }
};