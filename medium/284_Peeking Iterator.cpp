// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        m_empty=true;
        if(Iterator::hasNext()){
            m_peek=Iterator::next();
            m_empty=false;
        }
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        //create a new Obj with parameter *this
        //time and space consuming
        //return Iterator(*this).next();
        
        //override method
        if(!m_empty){
            return m_peek;
        }
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next(){
        int ret=m_peek;
        m_empty=true;
        if(Iterator::hasNext()){
            m_peek=Iterator::next();
            m_empty=false;
        }
        return ret;
    }
    
    bool hasNext(){
        return !m_empty;
    }
private:
    int m_peek;
    bool m_empty;
};