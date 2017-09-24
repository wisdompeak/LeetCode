class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) 
    {
        int N=nums.size();
        vector<int>len(N,1);
        vector<int>num(N,1);
        
        for (int i=1; i<N; i++)
        {
            int maxLen=1;
            int maxNum=1;
            for (int j=0; j<i; j++)
            {
                if (nums[i]<=nums[j])
                    continue;
                    
                if (len[j]+1>maxLen)
                {
                    maxLen=len[j]+1;
                    maxNum=num[j];
                }
                else if (len[j]+1==maxLen)
                {
                    maxNum+=num[j];
                }
            }
            len[i]=maxLen;
            num[i]=maxNum;
        }
        
        int maxLen=1;
        int maxNum=0;
        for (int i=0; i<N; i++)
        {
            if (len[i]>maxLen)
            {
                maxLen=len[i];
                maxNum=num[i];
            }
            else if (len[i]==maxLen)
                maxNum+=num[i];
        }
        
        return maxNum;
    }
    
};
