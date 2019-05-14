class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) 
    {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        
        int a = (stones[n-2]-stones[0]+1)-(n-1);
        int b = (stones[n-1]-stones[1]+1)-(n-1);
        int y = max(a,b);
        
        int j = 0;
        int x = INT_MAX;
        for (int i=0; i<n; i++)
        {
            while (j<n && stones[j]-stones[i]+1<n)
                j++;
            if (j==n) break;
            
            int gap;
            if (stones[j]-stones[i]+1==n)
                gap = n-(j-i+1);
            else if (j-i==n-1)
                gap = 2;
            else
                gap = n-(j-i);
            
            x = min(x,gap);
        }
        
        return {x,y};
    }
};
