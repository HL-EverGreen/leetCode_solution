class MedianFinder {
public:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
    /** initialize your data structure here. */
    MedianFinder() { //priority_queue
        
    }
    
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        if(large.size()>small.size()){
            small.push(large.top());
            large.pop();
        }
        /*
        if(!large.empty() && num>large.top()) large.push(num);
        else small.push(num);
        while(small.size()>large.size()+1){
            large.push(small.top());
            small.pop();
        }
        while(small.size()+1<large.size()){
            small.push(large.top());
            large.pop();
        }
        */
    }
    
    double findMedian() {
        if(small.size()>large.size()) return small.top();
        //else if(large.size()>small.size()) return large.top();
        else return (small.top()+large.top())/2.0;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */