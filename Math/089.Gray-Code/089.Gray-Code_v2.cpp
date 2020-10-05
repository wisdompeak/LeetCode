class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int>results;
        for (int i=0; i<(1<<n); i++)
            results.push_back(i^(i>>1));
        return results;
    }
};
