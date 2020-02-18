class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) 
    {
        int M = matrix.size();
        int N = matrix[0].size();
        
        int count = 0;
        for (int i=0; i<M; i++)
        {
            vector<int>temp(N,0);
            for (int j=i; j<M; j++)
            {
                for (int k=0; k<N; k++)
                    temp[k] += matrix[j][k];
                count += helper(temp,target);
            }
        }
        return count;                        
    }
    
    int helper(vector<int>&nums, int target)
    {
        int N = nums.size();
        int presum = 0;
        unordered_map<int,int>presumMap;
        presumMap[0] = 1;
        int count = 0;
        for (int j=0; j<N; j++)
        {
            presum += nums[j];
            if (presumMap.find(presum - target)!=presumMap.end())
                count+=presumMap[presum - target];
            presumMap[presum]+=1;
        }
        return count;
    }
};
