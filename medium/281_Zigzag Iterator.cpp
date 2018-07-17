class ZigzagIterator {
public:
    vector<int> i1;
    vector<int> i2;
    int index1;
    int index2;
    int flag;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        i1=v1;
        i2=v2;
        index1=0;
        index2=0;
        flag=0;
    }

    int next() {
        if(index1<i1.size() && index2<i2.size()){
            if(flag==0){
                index1++;
                flag=1;
                return i1[index1-1];
            }
            else{
                index2++;
                flag=0;
                return i2[index2-1];
            }
        }
        else if(index1>=i1.size() && index2<i2.size()){
            index2++;
            return i2[index2-1];
        }
        else if(index1<i1.size() && index2>=i2.size()){
            index1++;
            return i1[index1-1];
        }
    }

    bool hasNext() {
        if(index1>=i1.size()&&index2>=i2.size()){
            return false;
        }
        else return true;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */