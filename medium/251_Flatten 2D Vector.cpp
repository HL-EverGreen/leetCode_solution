class Vector2D {
public:
    vector<int> res;
    Vector2D(vector<vector<int>>& vec2d) {
        for(auto temp:vec2d)
            for(auto temp_int:temp)
                res.push_back(temp_int);
    }

    int next() {
        int result=res[0];
        res.erase(res.begin(),res.begin()+1);
        return result;
    }

    bool hasNext() {
        return !res.empty();
    }
};
// can use two iterator to save time
/*
class Vector2D {
public:
    
    Vector2D(vector<vector<int>>& vec2d) {
        row = vec2d.begin(); 
        endP = vec2d.end(); 
        
        if (row != vec2d.end()) {
            col = row->begin(); 
        }        
    }

    int next() {
        return *col++;
    }

    bool hasNext() {
        while (row != endP && col == row->end()) {
            row++;
            col = row->begin();            
        }
        return row != endP;
    }
    
private:
    vector<vector<int>> ::iterator row, endP;
    vector<int> ::iterator col; 
    
};
*/


/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */