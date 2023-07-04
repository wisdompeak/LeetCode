class Solution {
public:
    int longestString(int x, int y, int z) 
    {
        int t = x+y+z-max(0, (max(x,y)-min(x,y)-1));
        return t*2;        
    }
};
