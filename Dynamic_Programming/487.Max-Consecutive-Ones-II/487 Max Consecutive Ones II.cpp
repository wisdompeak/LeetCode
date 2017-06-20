class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
    if (nums.size()==0) return 0;
        
        int count1=0;
        int count2=0;
        int result=0;
        
        for (int i=0; i<nums.size(); i++)
        {
            if (i==0)
            {
                if (nums[i]==1)
                {
                    count1=1;
                    count2=1;
                }
                else
                {
                    count1=0;
                    count2=1;
                }
            }
            
            else
            {
                if (nums[i]==1)
                {
                    count1++;
                    count2++;
                }
                else if (nums[i]==0)
                {
                    count2=count1+1;
                    count1=0;
                }
            }
            
            result=max(result,count2);

            //cout<<count1<<count2<<endl;
        }
        
        return result;
        
        
    }
};
