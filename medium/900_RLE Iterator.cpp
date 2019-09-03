// design & array
// time complexity: RLEIterator(): O(n), next(): O(n)
// space complexity: O(n)
// 4ms, beats 97.5%

class RLEIterator {
public:
    RLEIterator(vector<int>& A) {
        arr = A;
        index = 0;
    }
    
    int next(int n) {
        while(index < arr.size()) {
            if(arr[index] < n) {        // Current number can't satisfy requirement
                n -= arr[index];
                index += 2;
            } else {                    // Current number can satisfy, so minus required `n`
                arr[index] -= n;
                return arr[index + 1];
            }
        }
        return -1;
    }
private:
    vector<int> arr;
    int index;
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */