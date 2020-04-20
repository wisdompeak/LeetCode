class Solution {
public:
    int numOfWays(int n) 
    {
        long colors2 = 6, colors3 = 6;
        long M = 1e9+7;
        
        for (int i=1; i<n; i++)
        {
            long temp2 = colors2, temp3 = colors3;
            colors2 = ((3*temp2)%M + (2*temp3)%M)%M;
            colors3 = ((2*temp2)%M + (2*temp3)%M)%M;
        }
        
        return (colors2+colors3)%M;
        
    }
};
