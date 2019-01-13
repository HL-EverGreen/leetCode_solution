class Solution {
public:
    string convert(string s, int numRows) {
        // string
        // time complexity: O(n), space complexity: O(n)
        // 16ms, beats 93.56%
        
        if(numRows <= 0) { return ""; }
        else if(numRows == 1) { return s; }
        
        vector<string> rcv(numRows, "");
        int cur_idx = 0;
        bool down = true;                   // whether next step go down or not
        string res;
        for(auto ch : s) {
            rcv[cur_idx] += ch;
            if(cur_idx == 0) { down = true; } 
            else if(cur_idx == numRows - 1) { down = false; }
            if(down) { cur_idx++; } 
            else { cur_idx--; }
        }
        
        for(auto elem : rcv) {
            res += elem;
        }
        return res;

        //use new
        /*
        if(numRows<=1) return s;
        const int len=s.length();
        string *str=new string[numRows], res;
        int row=0, step=1;
        
        for(int i=0;i<len;i++){       //numRows个string交替读
            str[row].push_back(s[i]);
            if(row==0) step=1;
            else if(row==numRows-1) step=-1;
            row+=step;
        }
        
        for(int i=0;i<numRows;i++) res.append(str[i]);
        delete[] str; //avoid memory leak
        return res;
        */
    }
};