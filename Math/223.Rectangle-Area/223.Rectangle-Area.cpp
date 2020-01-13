class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        long x1 = max(A,E);
        long y1 = max(B,F);
        long x2 = min(C,G);
        long y2 = min(D,H);
        
        long overlap;
        if (x1>=x2 || y1>=y2)
            overlap = 0;
        else
        
        return (long)(C-A)*(D-B) + (long)(G-E)*(H-F) - overlap;
    }
};
