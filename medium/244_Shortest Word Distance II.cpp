class WordDistance {
public:
    vector<string> wordlist;
    WordDistance(vector<string> words) {
        wordlist.insert(wordlist.end(),words.begin(),words.end());
    }
    
    int shortest(string word1, string word2) {
        int finalres=0;
        int temp=0;
        int flag=-1; //word1 or word2 flag
        bool frt=false; //first computation flag
        for(int i=0;i<wordlist.size();i++){
            if(wordlist[i]==word1){
                if(flag==1){
                    if(frt)
                        finalres=min(finalres,i-temp);
                    else{
                        finalres=i-temp;
                        frt=true;
                    }
                }
                temp=i;
                flag=0;
            }
            if(wordlist[i]==word2){
                if(flag==0){
                    if(frt)
                        finalres=min(finalres,i-temp);
                    else{
                        finalres=i-temp;
                        frt=true;
                    }
                }
                temp=i;
                flag=1;
            }
        }
        return finalres;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */