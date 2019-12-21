class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) 
    {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        
        int x = INT_MAX, y;
        if (stones[1]-stones[0] > stones[n-1]-stones[n-2])
            y = (stones[n-2]-stones[0]+1)-(n-1);
        else 
            y = (stones[n-1]-stones[1]+1)-(n-1);
        
        for (int i=0; i<stones.size(); i++)
        {
            int temp;
            int j = i;
            while (j<n && stones[j]-stones[i]+1 < n)
                j++;
            if (j==n) break;
            
            if (stones[j]-stones[i]+1==n)
                temp = (stones[j]-stones[i]+1) - (j-i+1);
            else
            {
                if (j-1-i+1 == n-1)
                    temp = 2;
                else
                    temp = n - (j-i);
            }
            x = min(x, temp);
            
        }
        
        return {x,y};
        
        
    }
};
