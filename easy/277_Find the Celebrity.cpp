// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        //violence solution
        /*
        for(int i=0;i<n;i++){
            bool flg=true;
            for(int j=0;j<n;j++){
                if(j==i) continue;
                flg=flg&&knows(j,i);
                if(!flg) break;
            }
            if(flg){
                for(int k=0;k<n;k++){
                    if(k==i) continue;
                    flg=flg&&(!knows(i,k));
                    if(!flg) break;
                }
                if(flg) return i;
            }
        }
        return -1;
        */
        
        //determine the candidate for celebrity first
        //First, A knows B then B is a candidate for celebrity and A is not
        int celeb = 0;
        for(int i=1;i<n;i++){
            if(knows(celeb, i))
                celeb = i;
        }
        
        //Now we need to check all values before the celeb, to see if they know him
        for(int i=0;i<n;i++){
            if(i == celeb) continue;
            else if(knows(i,celeb) && !knows(celeb,i))
                continue;
            else return -1;
        }
        
        return celeb;
    }
};