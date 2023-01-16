using LL = long long;
class Solution {
    LL total = 0;
    LL ret = 0;
public:
    long long countGood(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int j = 0;
        unordered_map<int,int>count;
        
        for (int i=0; i<n; i++)
        {
            while (j<n && total < k)
            {                
                total += diff(count, nums[j], 1);
                count[nums[j]]++;
                j++;
            }
            if (total >= k)
                ret += n-j+1;
            
            total += diff(count, nums[i], -1);
            count[nums[i]]--;
        }
        
        return ret;        
    }
    
    LL diff(unordered_map<int,int>&count, int num, int d)
    {
        LL m = count[num];
        LL old = m*(m-1)/2;
        m += d;
        LL now = m*(m-1)/2;
        return now - old;
    }
};
