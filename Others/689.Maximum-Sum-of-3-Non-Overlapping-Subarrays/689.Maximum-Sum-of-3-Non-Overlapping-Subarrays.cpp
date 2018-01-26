class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) 
    {
        int N=nums.size();
        
        vector<int>Sum(N);
        Sum[0]=nums[0];
        for (int i=1; i<N; i++)
            Sum[i]=Sum[i-1]+nums[i];        
        
        vector<int>LeftSum(N);
        vector<int>LeftIdx(N);
        int Ksum=0;
        for (int i=0; i<k; i++)
            Ksum+=nums[i];
        LeftSum[k-1]=Ksum;
        LeftIdx[k-1]=k-1;
        for (int i=k; i<N; i++)
        {
            Ksum+=nums[i];
            Ksum-=nums[i-k];
            if (Ksum>LeftSum[i-1])
            {
                LeftSum[i]=Ksum;
                LeftIdx[i]=i;
            }                
            else
            {
                LeftSum[i]=LeftSum[i-1];
                LeftIdx[i]=LeftIdx[i-1];
            }                
        }
        
        vector<int>RightSum(N);
        vector<int>RightIdx(N);
        Ksum=0;
        for (int i=N-1; i>=N-k; i--)
            Ksum+=nums[i];
        RightSum[N-k]=Ksum;
        RightIdx[N-k]=N-k;
        for (int i=N-k-1; i>=0; i--)
        {
            Ksum+=nums[i];
            Ksum-=nums[i+k];
            if (Ksum>RightSum[i+1])
            {
                RightSum[i]=Ksum;
                RightIdx[i]=i;
            }                
            else
            {
                RightSum[i]=RightSum[i+1];
                RightIdx[i]=RightIdx[i+1];
            }                
        }
        
        int temp=INT_MIN;
        vector<int>result(3);
        for (int i=k; i<=N-k-1; i++)
        {
            if (LeftSum[i-1]+Sum[i+k-1]-Sum[i-1]+RightSum[i+k]>temp)
            {
                temp = LeftSum[i-1]+Sum[i+k-1]-Sum[i-1]+RightSum[i+k];
                result = {LeftIdx[i-1]-k+1,i,RightIdx[i+k]};
            }
        }
        
        return result;        
    }
};
