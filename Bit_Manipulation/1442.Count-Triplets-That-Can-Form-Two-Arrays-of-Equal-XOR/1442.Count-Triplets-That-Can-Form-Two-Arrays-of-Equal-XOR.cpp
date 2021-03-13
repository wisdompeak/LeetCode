class Solution {
public:
    int countTriplets(vector<int>& arr) 
    {
        unordered_map<int,vector<int>>Map;
        Map[0].push_back(-1);
        int xorsum = 0;
        int ret = 0;
        for (int k=0; k<arr.size(); k++)
        {
            xorsum ^= arr[k];
            for (int i: Map[xorsum])
                ret += max(0, k - i -1);
            Map[xorsum].push_back(k);
        }
        return ret;
    }
};
