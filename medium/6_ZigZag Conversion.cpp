class Solution {
public:
    string convert(string s, int numRows) { //string
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
    }
};