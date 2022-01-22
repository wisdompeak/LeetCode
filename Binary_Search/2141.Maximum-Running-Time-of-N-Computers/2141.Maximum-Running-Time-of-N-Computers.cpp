using LL = long long;
class Solution {    
public:
    long long maxRunTime(int n, vector<int>& batteries) 
    {
        LL left = 0, right = LLONG_MAX/2;
        // sort(batteries.rbegin(), batteries.rend());
        
        while (left < right)
        {
            LL mid = right-(right-left)/2;
            if (checkOK(mid, batteries, n))            
                left = mid;                            
            else
                right = mid-1;                
        }
        return left;                
    }
    
    bool checkOK(LL T, vector<int>&nums, int n)
    {
        int count = 0;
        LL cur = 0;        
        for (int i=0; i<nums.size(); i++)
        {
            cur+=min((LL)nums[i], T);
            while (cur >= T)
            {
                count++;
                cur-=T;
            }
            if (count >= n)
                return true;
        }
        return false;
    }
};
