class Solution {
public:
    vector<int> numsGame(vector<int>& nums) 
    {
        for (int i=0; i<nums.size(); i++)
            nums[i] -= i;

        vector<int>rets;
        multiset<long>Set;        
        long M = 1e9+7;

        Set.insert(nums[0]);
        auto iter = Set.begin();
        long medium = nums[0];
        long total = 0;
        rets.push_back(0);

        for (int i=1; i<nums.size(); i++)
        {
            int t = nums[i];
            Set.insert(nums[i]);
            if ((Set.size()-1)%2==1)  // OOXOO
            {
                if (t<*iter)
                    iter = prev(iter);
                total += abs(medium - *iter);
            }
            else        //OOXOOO
            {
                if (t>=*iter)
                    iter = next(iter);
            }
            
            total += abs(t - *iter);
            total %= M;
            rets.push_back(total);
            medium = *iter;
        }
        return rets;
    }
};
