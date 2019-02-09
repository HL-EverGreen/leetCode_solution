class Solution {
public:
    bool isValid(string s) {
        // parentheses & stack
        // time complexity: O(n), space complexity: O(n)
        // 4ms, beats 100%
        
        stack<char> sta;
        for(auto ch : s) {
            // maybe a more clear style
            /*
            if(!mysta.empty()){
                if(mysta.top()=='[' && ch==']'
                  || mysta.top()=='(' && ch==')'
                  || mysta.top()=='{' && ch=='}'){
                    mysta.pop();
                    continue;
                }
            }
            mysta.push(ch);
            */
            
            if(ch == '(' || ch == '[' || ch == '{') 
                sta.push(ch);
            else if(sta.empty()) 
                return false;
            else if((ch == ')' && sta.top() == '(') || (ch == ']' && sta.top() == '[') || (ch == '}' && sta.top() == '{')) 
                sta.pop();
            else 
                return false;
        }
        if(sta.empty()) return true;
        else return false;
    }
};