class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) 
    {
        multiset<int>Set;
        for (int i=0; i<k; i++)        
            Set.insert(nums[i]);
        
        auto pos=Set.begin();
        for (int i=0; i<k/2; i++)
            pos=next(pos,1);
        
        vector<double>results;
        
        for (int i=k; i<=nums.size(); i++)
        {
            if (k%2==1)
                results.push_back(*pos);
            else
                results.push_back(*pos/2.0+*prev(pos,1)/2.0);
            
            if (i==nums.size()) break;
            
            Set.insert(nums[i]);
            
            if (k%2==1)   // OXO
            {
                if (nums[i]>=*pos)
                    pos++;
                                
                // OOXO
                if (nums[i-k]>*pos)
                    pos--;
                else if (nums[i-k]<*pos)
                    ;
                else if (nums[i-k]==*pos && *prev(pos,1)!=*pos)  
                    // 如果X左边是个重复元素，则无需改动；如果X左边不是重复元素，则X会被删除，指针需左移
                    pos--;                
            }
            else    // OOXO
            {
                if (nums[i]<*pos)
                    pos--;
                
                // OOXOO
                if (nums[i-k]<*pos)
                    pos++;
                else if (nums[i-k]>*pos)
                    ;
                else if (nums[i-k]==*pos)
                    // 如果X左边是个重复元素，则会删除那个O；如果X左边不是重复元素，则会删除X。两种情况下指针都需右移
                    pos++;
            }
            
            Set.erase(Set.lower_bound(nums[i-k]));     
        }
        
        return results;
        
    }
};
