class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>>rets;
        vector<int>comb;
        for (int i=1; i<=k; i++)
            comb.push_back(i);
        rets.push_back(comb);

        while (1)
        {            
            int i = k-1;
            while (i>=0 && comb[i]==i+1+n-k)
                i--;
            if (i==-1) break;
            comb[i]++;
            for (int j=i+1; j<k; j++)
                comb[j] = comb[j-1]+1;
            rets.push_back(comb);
        }
        return rets;        
    }
};
