class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<int>result;        
        for (int i=0; i<=nums1.size(); i++)
        {            
            int j=k-i;
            if (j<0 || j>nums2.size()) continue;
            vector<int>p1 = findMax(nums1,i);
            vector<int>p2 = findMax(nums2,j);              
            vector<int>temp = merge(p1,p2);
            result = max(temp,result);
        }
        return result;
    }
    
    vector<int> findMax(vector<int> nums, int k)
    {        
        int drop = nums.size()-k;
        vector<int>result;
        
        for (int i=0; i<nums.size(); i++)
        {                            
            while (drop>0 && result.size()>0 && nums[i]>result.back())
            {
               result.pop_back();
               drop--;
            }
            result.push_back(nums[i]);
        }
        result.resize(k);
        return result;
    }
    
    vector<int> merge(vector<int>nums1, vector<int>nums2)
    {
        vector<int>result;
        while (nums1.size()+nums2.size()>0)
        {
            if (nums1>nums2)
            {
                result.push_back(nums1[0]);
                nums1.erase(nums1.begin());
            }
            else
            {
                result.push_back(nums2[0]);
                nums2.erase(nums2.begin());
            }
        }
        return result;            
    }
};
