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
