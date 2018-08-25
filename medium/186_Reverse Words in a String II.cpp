class Solution {
public:
    void reverseWords(vector<char>& str) {//vector

        //more simple and efficient method using reverse(24ms)
        reverse(str.begin(),str.end());
        int s_size=str.size();
        for(int i=0,j=0;i<s_size;i=j+1){
            for(j=i;j<s_size && !isblank(str[j]);j++);
            reverse(str.begin()+i,str.begin()+j);
        }
        
        //28ms
        /*
        vector<vector<char>> tmp;
        int s_size=str.size(), num_word=0;
        for(char ch:str){
            if(ch!=' '){
                if(num_word==tmp.size()) tmp.push_back(vector<char>());
                tmp[num_word].push_back(ch);
            }else num_word++;
        }
        
        int index=0;
        for(char& ch:str){
            if(index==tmp[num_word].size()){
                num_word--;
                index=0;
                ch=' ';
                continue;
            }
            ch=tmp[num_word][index++];
        }
        */
    }
};