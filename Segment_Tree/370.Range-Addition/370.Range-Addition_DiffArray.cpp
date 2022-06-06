class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) 
    {
        vector<int>diff(length+1,0);
        for (auto x:updates)
        {
            diff[x[0]]+=x[2];
            diff[x[1]+1]-=x[2];
        }
        vector<int>results;
        int cur = 0;
        for (int i=0; i<length; i++)
        {
            cur+=diff[i];
            results.push_back(cur);
        }
        return results;
    }
};
