class Solution {
public:
    int deleteAndEarn(vector<int>& nums) 
    {
        vector<int>gain(1e5+1,0);
        for (int x:nums)
            gain[x]+=x;
            
        int p = 0;  // robbed the last one
        int q = 0;  // did not rob the last one
        for (int i=1; i<=1e5; i++)
        {
            int p_tmp = p;
            int q_tmp = q;
            p = q_tmp + gain[i];
            q = max(q_tmp,p_tmp);
        }
        
        return max(p,q);
    }
};
