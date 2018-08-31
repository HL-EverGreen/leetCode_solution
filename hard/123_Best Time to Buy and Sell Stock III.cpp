class Solution {
public:
    int maxProfit(vector<int>& prices) { //dp
        int states[2][4]={INT_MIN,0,INT_MIN,0};
        int day=prices.size(), cur=0, next=1;
        for(int i=0;i<day;i++){
            states[next][0]=max(states[cur][0],-prices[i]);               //1 buy
            states[next][1]=max(states[cur][1],states[cur][0]+prices[i]); //1 buy 1 sell
            states[next][2]=max(states[cur][2],states[cur][1]-prices[i]); //2 buy 1 sell
            states[next][3]=max(states[cur][3],states[cur][2]+prices[i]); //2 buy 2 sell
            swap(cur,next);
        }
        return max(states[cur][1],states[cur][3]);
    }
};