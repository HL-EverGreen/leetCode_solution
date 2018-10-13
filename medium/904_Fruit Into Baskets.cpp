class Solution {
public:
    int totalFruit(vector<int>& tree) { //max subarray with two distinct characters
        //two variables solution, much more faster
        int cur = 0, lastOneCount = 0, res = 0, num1 = tree[0], num2 = tree[0];
        for(int fruit : tree){
            if(fruit == num2){
                lastOneCount++;
                cur++;
            }else if(fruit == num1){
                lastOneCount = 1;
                cur++;
                num1 = num2;
                num2 = fruit;
            }else{
                cur = lastOneCount + 1;
                lastOneCount = 1;
                num1 = num2;
                num2 = fruit;
            }
            res = max(res, cur);
        }
        return res;

        //LC 159 solution, find max subarray with two distinct characters
        /*
        int size=tree.size(), start=0, len=1, count=0;
        unordered_map<int,int> basket;
        for(int i=0;i<size;i++){
            int tmp=++basket[tree[i]];
            if(tmp==1) count++;
            while(count>2){
                tmp=--basket[tree[start]];
                if(tmp==0) count--;
                start++;
            }
            len=max(i-start+1,len);
        }
        return len;
        */
    }
};