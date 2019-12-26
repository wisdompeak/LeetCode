class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int>rets;
        rets.push_back(0);
        for (int i=0; i<n; i++)
        {
            int len = rets.size();
            for (int j=len-1; j>=0; j--)
            {
                rets.push_back(rets[j]| (1<<i));
            }
        }
        return rets;
    }
};
