class Solution {
    static bool cmp(vector<int>&a, vector<int>&b)
    {
        return a[1]<b[1];
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(), pairs.end(), cmp);
        int i=0, count = 0;
        while (i<pairs.size())
        {
            int j = i;
            while (j<pairs.size() && pairs[j][0]<=pairs[i][1])
                j++;
            count++;
            i = j;
        }
        return count;
    }
};
