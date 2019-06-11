void operator+=(vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); i++) {
        a[i] += b[i];
    }
}
    
void operator-=(vector<int>& a, const vector<int>& b) {
    for(int i = 0; i < a.size(); i++) {
        a[i] -= b[i];
    }
}

int operator*(const vector<int>& a, const vector<int>& b) {
    int res = 0;
    for(int i = 0; i < a.size(); i++) {
        res += a[i] * b[i];
    }
    return res;
}

bool operator<(const vector<int>& a, int b) {
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < b) {
            return true;
        }
    }
    return false;
}

class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
        // DFS
        // 12ms, beats 80.32%
        
        // Main idea:
        // In each recursive, calculate normal price using all basic price.
        // Then, try to add special offer, do DFS.
        
        if(needs < 0) { return INT_MAX; }

        /* Calculate basic price */
        int res = cost + needs * price;
        
        /* DFS */
        for(auto& spe : special) {
            /* Prune */
            if(cost + spe.back() > res) { continue; }
            
            needs -= spe;
            cost += spe.back();
            res = min(res, shoppingOffers(price, special, needs, cost));
            needs += spe;
            cost -= spe.back();
        }
        return res;
    }
};