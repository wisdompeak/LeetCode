class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) 
    {
        int total = accumulate(A.begin(),A.end(),0);
        int n = A.size();
        if (n==1) return false;
        auto dp = vector<int>(total+1,0);
        dp[0] = 1;

        int curSum = 0;

        for (auto a: A)
        {
            curSum+=a;
            for (int sum = curSum; sum>=a; sum--)
            {
                dp[sum] |= dp[sum-a]<<1;

                if (sum*n%total!=0) continue;
                int num = sum*n/total;
                if (num!=0 && num!=n && (dp[sum]&(1<<num))) return true;
            }            
        }
        return false;        
    }
};
