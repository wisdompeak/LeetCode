class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& nums) 
    {
        int n = nums.size();
        int m = 0;
        unordered_map<int,int>Map;
        for (int x: nums)
        {
            Map[x]++;
            m = max(m, Map[x]);
        }
                            
        for (int k=m; k>=1; k--)                
        {
            int count = 0;
            for (auto [_, x]: Map)
            {
                if (x % k <= x/k)
                {
                    count += ceil(x*1.0/(k+1));
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
