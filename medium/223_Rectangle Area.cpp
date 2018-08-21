class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {//vector_sort
        int res=(C-A)*(D-B)+(G-E)*(H-F);
        if(C<=E || B>=H || G<=A || D<=F) return res;
        vector<int> rect_a;
        rect_a.push_back(A);
        rect_a.push_back(C);
        rect_a.push_back(E);
        rect_a.push_back(G);
        
        vector<int> rect_b;
        rect_b.push_back(B);
        rect_b.push_back(D);
        rect_b.push_back(F);
        rect_b.push_back(H);
        
        sort(rect_a.begin(),rect_a.end());
        sort(rect_b.begin(),rect_b.end());
        return res-(rect_a[2]-rect_a[1])*(rect_b[2]-rect_b[1]);
    }
};