class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int>Set(nums.begin(),nums.begin()+k-1);                
        multiset<int>::iterator mid;
        multiset<int>::iterator mid2;
        
        vector<double>results;
            
        for (int i=k-1; i<nums.size(); i++)
        {
            Set.insert(nums[i]);
            
            if (k%2==1)
            {
                mid=next(Set.begin(),k/2);
                results.push_back(*mid);
            }
            else
            {
                mid=next(Set.begin(),k/2);
                mid2=prev(mid,1);
                results.push_back((*mid*1.0+*mid2*1.0)/2.0);
            }                
            
            Set.erase(Set.lower_bound(nums[i-k+1]));
        }
        
        return results;
    }
};
