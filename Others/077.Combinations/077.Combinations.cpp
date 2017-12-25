class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<int>comb(k,0);
        vector<vector<int>>results;
        int i=0;
        
        while (i>=0)
        {
            comb[i]++;
            
            if (comb[i]>n)
                i--;
            else if (i==k-1)
                results.push_back(comb);
            else if (i<k-1)
            {
                i++;
                comb[i]=comb[i-1];
            }
        }
        
        return results;
    }
};
