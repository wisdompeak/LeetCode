class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) 
    {
        unordered_map<int,int>Map;
        Map[0] = 1;
        int sum = 0, ret = 0;
        for (int i=0; i<A.size(); i++)
        {
            sum += A[i];
            if (Map.find(sum-S)!=Map.end())
                ret+=Map[sum-S];
            Map[sum]+=1;
        }
        return ret;

    }
};
