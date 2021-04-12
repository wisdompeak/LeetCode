class Solution {
public:
    vector<int> constructArray(int n, int k) 
    {
        vector<int>ret({k+1});
        int count = 1;
        for (int d=k; d>=1; d--)
        {
            if (count%2==1)
                ret.push_back(ret.back()-d);
            else
                ret.push_back(ret.back()+d);
            count++;
        }
        reverse(ret.begin(), ret.end());
        for (int i=k+2; i<=n; i++)
            ret.push_back(i);
        
        return ret;
        
    }
};
