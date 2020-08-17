class Solution {
    unordered_map<int,int>ans;
public:
    int minDays(int n) 
    {
        if (n==1) return 1;
        if (n==2) return 2;
        if (n==3) return 2;

        if (ans.find(n)!=ans.end())
            return ans[n];
        
        int ret = min(n%2+1+minDays(n/2), n%3+1+minDays(n/3));
        ans[n] = ret;

        return ret;
    }
};
