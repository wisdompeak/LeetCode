class Solution {        
    long M = 1e9+7;
    struct hashGenerator {
        size_t operator()(const pair<int,int>& p) const 
        {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };

public:
    vector<int> solve(vector<int>& nums, vector<vector<int>>& queries) 
    {        
        int n = nums.size();
        unordered_map<pair<int,int>, vector<long>, hashGenerator>presum;                
        vector<int>rets;        
        
        for (auto query: queries)
        {
            int s = query[0];
            int d = query[1];
            if (d >= sqrt(n))
            {
                long sum = 0;
                int i = s;
                while (i < n)
                {
                    sum = (sum+nums[i])%M;
                    i+=d;
                }
                rets.push_back(sum);                    
            }
            else
            {
                int offset = s%d;
                if (presum.find({d,offset})==presum.end())
                {
                    vector<long>temp((n-1-offset)/d+1);
                    long sum = 0;
                    int i = 0;
                    while (offset + i*d < n)
                    {
                        sum = (sum + (long)nums[offset + i*d])%M;                    
                        temp[i] = sum;
                        i++;
                    }
                    presum[{d,offset}] = temp;
                }                
                long x = presum[{d,offset}][(n-1-offset)/d];
                long y = (s-1-offset) < 0? 0: presum[{d,offset}][(s-1-offset)/d];
                rets.push_back(((x - y )%M + M)%M);                
            }
        }
        return rets;        
    }
};
