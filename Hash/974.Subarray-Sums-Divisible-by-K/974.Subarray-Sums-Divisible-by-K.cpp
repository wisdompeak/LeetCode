class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) 
    {
        unordered_map<int,int>Map;

        Map[0] = 1;
        int presum = 0;
        int ret = 0;
        for (int i=0; i<A.size(); i++)
        {
            presum += A[i];
            int r = presum > 0 ? presum%K : (presum%K+K)%K;
            ret += Map[r];
            Map[r]++;
        }
        return ret;
    }
};
