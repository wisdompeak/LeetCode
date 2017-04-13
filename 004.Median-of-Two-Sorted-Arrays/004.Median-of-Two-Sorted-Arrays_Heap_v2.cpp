class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        int m = nums1.size();
        int n = nums2.size();
        
        if ((m+n) % 2 ==1)
            return FindKthElement(nums1,nums2,(m+n)/2+1);
        else
            return 0.5*(FindKthElement(nums1,nums2,(m+n)/2)+FindKthElement(nums1,nums2,(m+n)/2+1));
    }
    
    double FindKthElement(vector<int> nums1, vector<int> nums2, int k)
    {
        int count = 0;
        int result = 0;
        priority_queue<pair<int,int>>q;
        
        if (nums1.size()!=0)
        {
            q.push({nums1.back(),1});
            nums1.pop_back();
        }
        if  (nums2.size()!=0)
        {
            q.push({nums2.back(),2});
            nums2.pop_back();
        }
        
        while (count<k)
        {
            result = q.top().first;
            count++;
            int label = q.top().second;
            q.pop();
            
            if (nums1.size()==0 && nums2.size()!=0)
            {
                q.push({nums2.back(),2});
                nums2.pop_back();
            }
            else if (nums2.size()==0  && nums1.size()!=0)
            {
                q.push({nums1.back(),1});                
                nums1.pop_back();
            }
            else
            {
                if (label==1)
                {
                    q.push({nums1.back(),1});                
                    nums1.pop_back();                    
                }
                else
                {
                    q.push({nums2.back(),2});                
                    nums2.pop_back();                    
                }
            }
        }
        
        return result;
    }
};
