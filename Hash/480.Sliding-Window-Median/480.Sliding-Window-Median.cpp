class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<double>Set(nums.begin(),nums.begin()+k);
        multiset<double>::iterator mid=next(Set.begin(),k/2);
        
        vector<double>results;
            
        for (int i=k; i<=nums.size(); i++)
        {            
            results.push_back((*mid+*prev(mid,1-k%2))/2.0);
            if (i==nums.size()) return results;
                
            Set.insert(nums[i]);
                
            if (nums[i]<*mid) mid--;                                
                
            if (nums[i-k]<=*mid) mid++;
                
            Set.erase(Set.lower_bound(nums[i-k]));            
        }
        
        return results;
    }
};
