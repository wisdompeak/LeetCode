class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) 
    {
        int n = aliceValues.size();
        vector<pair<int,int>>tmp(n);
        for (int i=0; i<n; i++)
        {
            tmp[i] = {aliceValues[i]+bobValues[i],i};
        }
        sort(tmp.begin(), tmp.end());
        reverse(tmp.begin(), tmp.end());
               
        int x = 0, y = 0;
        for (int i=0; i<n; i++)
        {
            if (i%2==0)
                x += aliceValues[tmp[i].second];                                
            else            
                y += bobValues[tmp[i].second];            
        }
        
        if (x>y)
            return 1;
        else if (x==y)
            return 0;
        else
            return -1;
        
    }
};
