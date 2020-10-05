class Solution {
public:
    vector<int> grayCode(int n) 
    {
        vector<int>results(1<<n);
        for (int i=0; i<(1<<n); i++)
            results[i] = (i^(i>>1));
        return results;
    }
};
