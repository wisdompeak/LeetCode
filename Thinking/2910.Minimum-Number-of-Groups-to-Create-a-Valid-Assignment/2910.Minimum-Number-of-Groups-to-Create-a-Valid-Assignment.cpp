class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) 
    {
        int n = nums.size();        
        unordered_map<int,int>Map;        
        for (int x: nums) Map[x]++;

        int m = INT_MAX;
        for (auto [_, x]: Map) 
            m = min(m, x);
                            
        for (int k=m+1; k>=1; k--)                
        {
            int count = 0;
            for (auto [_, x]: Map)
            {
                int q = x / k;
                int r = x % k;
                if (r==0 || k-r <= q+1)
                {
                    count += ceil(x*1.0 / k);
                }
                else
                {
                    count = -1;
                    break;
                }
                    
            }    
            if (count != -1) return count;        
        }

        return 0;
    }    
};
