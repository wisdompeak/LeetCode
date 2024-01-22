using LL = long long;
class Solution {    
public:
    long long minimumCost(vector<int>& nums, int k, int dist) 
    {
        int n = nums.size();
        
        multiset<int>Set1;
        multiset<int>Set2;
        
        LL sum = 0;
        LL ret = LLONG_MAX;
        
        k--;
        
        for (int i=1; i<n; i++)
        {        
            if (Set1.size() < k)
            {
                Set1.insert(nums[i]);
                sum += nums[i];
            }                
            else if (*Set1.rbegin() <= nums[i])
                Set2.insert(nums[i]);
            else
            {
                Set2.insert(*Set1.rbegin());
                sum -= *Set1.rbegin();
                Set1.erase(prev(Set1.end()));
                Set1.insert(nums[i]);
                sum += nums[i];
            }
            
            if (i>=dist+1)
            {
                ret = min(ret, sum);
                
                int t = nums[i-dist];
                if (Set2.find(t)!=Set2.end())
                    Set2.erase(Set2.find(t));
                else
                {
                    Set1.erase(Set1.find(t));
                    sum -= t;
                    if (!Set2.empty()) 
                    {
                        Set1.insert(*Set2.begin());
                        sum += *Set2.begin();
                        Set2.erase(Set2.begin());                    
                    }
                }
            }
        }
        
        return ret + nums[0];        
        
    }
};
