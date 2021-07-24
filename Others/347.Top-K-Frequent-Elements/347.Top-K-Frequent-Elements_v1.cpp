class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>freq;
        for (auto x: nums)
            freq[x]++;

        int left = 0, right = INT_MAX;
        while (left < right)
        {
            int mid = right - (right-left)/2;
            if (count(freq, mid)>=k)
                left = mid;
            else
                right = mid-1;
        }

        int f = left;

        vector<int>rets;
        for (auto x: freq)
        {
            if (x.second >= f)
                rets.push_back(x.first);
        }
        return rets;
    }

    int count(unordered_map<int,int>&freq, int th)
    {
        int ret = 0;
        for (auto x: freq)
            ret += x.second >=th;
        return ret;
    }
};
