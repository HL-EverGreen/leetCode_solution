class Solution {
public:
    int largestRectangleArea(vector<int>& heights) { //stack_large_rectangle_in_histogram
        int h_size=heights.size(), res=0, temp, start_idx;
        stack<int> sta;
        if(h_size==0) return 0;
        heights.push_back(0);
        for(int i=0;i<=h_size;i++){
            while(sta.size()>0 && heights[sta.top()]>=heights[i]){
                temp=heights[sta.top()];
                sta.pop();
                start_idx=sta.empty()? -1 : sta.top();
                res=max(res,temp*(i-start_idx-1));
            }
            sta.push(i);
        }
        return res;
    }
};