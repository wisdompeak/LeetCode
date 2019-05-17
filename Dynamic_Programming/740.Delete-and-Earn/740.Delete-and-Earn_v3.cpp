class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        if (nums.size()==0) return 0;
        map<int,int>Map;
        for (auto x:nums)
            Map[x]++;
        
        vector<pair<int,int>>A;
        for (auto x:Map)
            A.push_back(x);
        
        int p = A[0].first*A[0].second, q = 0;
        for (int i=1; i<A.size(); i++)
        {
            int p_temp = p, q_temp = q;
            if (A[i].first!=A[i-1].first+1)
            {
                p = max(p_temp,q_temp) + A[i].first*A[i].second;
                q = max(p_temp,q_temp);
            }
            else
            {
                p = q_temp + A[i].first*A[i].second;
                q = max(p_temp,q_temp);
            }
        }
        
        return max(p,q);
        
    }
};
