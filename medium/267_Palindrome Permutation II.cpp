class Solution {
public:
    vector<string> generatePalindromes(string s) {//unordered map & palindrome
        //the main idea is to find the mid element(if exist), and construct half of the string first
        //then compute all permutations of the string #half#
        //then reverse and joint original and reversed string(if exist mid element, also need to add it in the middle position)
        vector<string> res;
        unordered_map<char,int> counts;
        for(char ch:s) counts[ch]++;
        int odd=0;
        char mid;
        string half;
        for(auto p:counts){
            if(p.second & 1){
                odd++;
                mid=p.first;
                if(odd>1) return res; //if at least two elements occur oddly, then can't find any palindromes
            }
            half+=string(p.second/2,p.first);
        }
        res=permutations(half); //return all permutations of string #half#
        for(auto& p:res){
            string tmp(p);
            reverse(tmp.begin(),tmp.end());
            if(odd) tmp=mid+tmp; //add middle element
            p+=tmp;
        }
        return res;
    }
    
    vector<string> permutations(string half){
        vector<string> perm;
        string tmp(half);
        do{
            perm.push_back(half);
            next_permutation(half.begin(),half.end());
        }while(half!=tmp);
        return perm;
    }
};