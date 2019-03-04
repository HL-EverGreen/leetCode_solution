class Solution { 
public:
    /*
    int partition(vector<int>& nums, int left, int right) {//quick sort
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
        
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
    */
    int findKthLargest(vector<int>& nums, int k){
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            pq.pop(); 
        return pq.top();    
    }
};


// quick select like quick sort
/*
int i, m,n, pivot, head =0, tail=nums.size()-1, maxV;
    
    while(1)
    {
        m = head, n= tail;
        pivot = nums[m++];
        while(m<=n)
        {
            if(nums[m]>=pivot) m++;
            else if(nums[n]<pivot) n--;
            else {swap(nums[m++], nums[n--]);}
        }
        if(m-head == k) return pivot;
        else if(m-head < k) {k -= (m-head); head = m;  }
        else {tail = m-1;head = head+1;}
    }
*/