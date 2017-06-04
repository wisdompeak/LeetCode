class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int left=1;
        int right=nums.size()-1;
        int mid;
        
        while (left<right)
        {
            mid = left+(right-left)/2;
            int count=0;
            for (int i=0; i<nums.size(); i++)
                if (nums[i]<=mid) count++;
            
            if (count> mid)
                right = mid;
            else
                left = mid+1;
                
            //cout<<left<<right<<endl;
        }
        
        return left;
        
    }
};
