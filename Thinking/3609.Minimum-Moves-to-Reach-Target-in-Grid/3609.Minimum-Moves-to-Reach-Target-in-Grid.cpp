class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {             
        if (sx > tx || sy > ty) return -1;
        if (sx == tx && sy == ty) return 0;  

        if (tx < ty)
            return minMoves(sy, sx, ty, tx);

        if (tx==ty) {
            int temp1 = minMoves(sy, sx, 0, ty);
            if (temp1!=-1) return temp1+1;

            int temp2 = minMoves(sy, sx, tx, 0);
            if (temp2!=-1) return temp2+1;

            return -1;            
        }
        
        if (tx > 2*ty) {
            if (tx%2==1) return -1;
            int temp = minMoves(sx, sy, tx/2, ty);
            if (temp==-1) return -1;
            else return temp+1;
        } else {
            int temp = minMoves(sx, sy, tx-ty, ty);
            if (temp==-1) return -1;
            else return temp+1;
        }
            
        return -1;
    }
};
