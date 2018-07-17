class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int finalres=0;
        int temp=0;
        int flag=-1; //word1 or word2 flag
        bool frt=false; //first computation flag
        for(int i=0;i<words.size();i++){
            if(words[i]==word1){
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
            if(words[i]==word2){
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