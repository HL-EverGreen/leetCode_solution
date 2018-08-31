class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) { //total
        //if total<0(which means total gas<total cost), there is no result
        //leave the minmum step in the last
        int day=gas.size(),start,minsum=INT_MAX,total=0;
        for(int i=0;i<day;i++){
            total+=gas[i]-cost[i];
            if(total<minsum){
                minsum=total;
                start=i+1;
            }
        }
        return total<0?-1:start%day;

        //force solution
        /*
        int remain_gas,g_size=gas.size(),c_size=cost.size(),index;
        if(g_size!=c_size) return -1;
        for(int i=0;i<gas.size();i++){
            int j=i,remain_gas=0;
            for(;j<i+g_size;j++){
                index=j%g_size;
                remain_gas+=gas[index]-cost[index];
                if(remain_gas<0) break;
            }
            if(j==i+g_size) return i; 
        }
        return -1;
        */
    }
};