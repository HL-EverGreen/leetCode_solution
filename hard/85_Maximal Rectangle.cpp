class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) { // find max rectangle in Histogram
        //main idea is to divide the matrix into each lines and transform into histogram
        //so the question transform to find max rectangle in histogram
        if(matrix.empty()) return 0;
        int maxRec = 0;
        vector<int> height(matrix[0].size(), 0);
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == '0') height[j] = 0;
                else height[j]++;
            }
            maxRec = max(maxRec, largestRectangleArea(height));
        }
        return maxRec;
    }

    int largestRectangleArea(vector<int> &height) { //use LC84 solution
        //a more easy to understand version
        int h_size=height.size(), res=0, temp, start_idx;
        stack<int> sta;
        if(h_size==0) return 0;
        height.push_back(0);
        for(int i=0;i<=h_size;i++){
            while(sta.size()>0 && height[sta.top()]>=height[i]){
                temp=height[sta.top()];
                sta.pop();
                start_idx=sta.empty()? -1 : sta.top();
                res=max(res,temp*(i-start_idx-1));
            }
            sta.push(i);
        }
        return res;

        //not easy to understand
        /*
        stack<int> s;
        height.push_back(0);
        int maxSize = 0;
        for(int i = 0; i < height.size(); i++){
            if(s.empty() || height[i] >= height[s.top()]){
                s.push(i);
            }
            else{
                int temp = height[s.top()];
                s.pop();
                maxSize = max(maxSize, temp*(s.empty()?i:i-1-s.top()));
                i--;
            }
        }
        return maxSize;
        */
    }
};