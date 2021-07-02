class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) 
    {
        unordered_map<int,int>Map;

        Map[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i=0; i<A.size(); i++)
        {
            sum+=A[i];
            int r = sum > 0 ? sum%K : (sum%K+K)%K;
            count+=Map[r];
            Map[r]++;
        }
        return count;
    }
};
