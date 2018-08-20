class Solution {
public:
    bool isValid(string s) {//stack
        stack<char> mysta;
        int s_size=s.size();
        for(char& ch:s){    // can use (char& ch:s) instead of (int i=0;i<s_size;i++)
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
            
            //a better logic
            if((ch=='[') || (ch=='{') || (ch=='('))
                mysta.push(ch);
            else if(mysta.empty())
                return false;
            else if((mysta.top()=='[' && ch==']') || (mysta.top()=='(' && ch==')') || (mysta.top()=='{' && ch=='}'))
                mysta.pop();
            else
                return false;
        }
        if(mysta.empty()) return true;
        else return false;
    }
};