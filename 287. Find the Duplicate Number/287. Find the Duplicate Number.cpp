class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        int left=1;
        int n=nums.size()-1;
        int right=n;
        int mid;
        
        while (left<right)
        {
            mid=left+(right-left)/2;
            
            //cout<<left<<mid<<right<<endl;
            
            int count=0;
            for (int i=0; i<nums.size(); i++)
                if (nums[i]>mid) count++;
            //cout<<count<<endl;
                
            if (count > (n-mid))
                left=mid+1;
            else
                right=mid;
        }
        
        return left;
        
    }
};
