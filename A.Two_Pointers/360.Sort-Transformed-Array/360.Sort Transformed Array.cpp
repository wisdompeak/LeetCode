class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) 
    {
        vector<int>result;
        
        if (a==0)
        {
            for (int i=0; i<nums.size(); i++)
                result.push_back(b*nums[i]+c);
            if (b<0)
                reverse(result.begin(),result.end());
        }
        else 
        {
            int flag = (a>0);
            float mid=-b/2.0/a;
            
            int left=0;
            int right=nums.size()-1;
            while (left<=right)
            {
                if (abs(mid-nums[left])>abs(mid-nums[right]))
                {
                    result.push_back(a*nums[left]*nums[left]+b*nums[left]+c);
                    left++;
                }
                else
                {
                    result.push_back(a*nums[right]*nums[right]+b*nums[right]+c);
                    right--;
                }                
            }            
            if (flag==1) reverse(result.begin(),result.end());            
        }        
        return result;        
    }
};
