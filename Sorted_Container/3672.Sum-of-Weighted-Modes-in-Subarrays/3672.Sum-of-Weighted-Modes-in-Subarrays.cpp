class Solution {
public:
    long long modeWeight(vector<int>& nums, int k) {
        map<int,set<int>>freq2val;
        unordered_map<int,int>val2freq;
        long long ret = 0;

        for (int i=0; i<nums.size(); i++) {
            int x = nums[i];
            int f = val2freq[x];
            freq2val[f].erase(x);
            if (freq2val[f].empty())
                freq2val.erase(f);
            val2freq[x]=f+1;
            freq2val[f+1].insert(x);

            if (i>=k-1) {
                int x = *(freq2val.rbegin()->second.begin());
                ret += (long long)x*val2freq[x];

                x = nums[i-k+1];
                int f = val2freq[x];
                freq2val[f].erase(x);
                if (freq2val[f].empty())
                    freq2val.erase(f);
                val2freq[x] = f-1;
                if (f!=1)
                    freq2val[f-1].insert(x);
            }
        }
        return ret;
    }
};
