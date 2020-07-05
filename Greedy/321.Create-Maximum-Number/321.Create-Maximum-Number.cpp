class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int K) 
    {
        vector<int> ret;
        for (int i=0; i<=K; i++)
        {
            if (i>nums1.size()) continue;
            if (K-i>nums2.size()) continue;
            vector<int>p1 = findMax(nums1, i);
            vector<int>p2 = findMax(nums2, K-i);
            vector<int>temp = merge(p1, p2);
            ret = max(ret, temp);            
        }
        return ret;
    }
    
    vector<int> findMax(vector<int>&nums, int k)
    {
        int drop = nums.size()-k;
        vector<int>ret;
        
        for (int i=0; i<nums.size(); i++)
        {
            while (drop>0 && ret.size()>0 && nums[i] > ret.back())
            {
                ret.pop_back();
                drop--;
            }
            ret.push_back(nums[i]);
        }
        ret.resize(k);
        return ret;
    }
    
    vector<int> merge(vector<int>&p1, vector<int>&p2)
    {
        vector<int>ret;
        int L = p1.size()+p2.size();
        for (int i=0; i<L; i++)
        {
            if (p1 > p2)
            {
                ret.push_back(p1[0]);
                p1.erase(p1.begin());
            }
            else
            {
                ret.push_back(p2[0]);
                p2.erase(p2.begin());
            }                
        }
        return ret;
    }
};
