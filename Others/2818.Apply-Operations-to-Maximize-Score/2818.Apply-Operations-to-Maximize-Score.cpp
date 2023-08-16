using LL = long long;
LL M = 1e9+7;
using PII=pair<LL,LL>;
class Solution {
public:
    LL quickMul(LL x, LL N) {
        if (N == 0) {
            return 1;
        }
        LL y = quickMul(x, N / 2) % M;
        return N % 2 == 0 ? (y * y % M) : (y * y % M * x % M);
    }
    
    vector<int>Eratosthenes(int n)
    {
        vector<int>q(n+1,0);        
        for (int i=2; i<=n; i++)
        {
            if (q[i]>=1) continue;
            q[i] = 1;
            int j=i*2;
            while (j<=n)
            {
                q[j]+=1;
                j+=i;
            }
        }        
        return q;
    }
    
    int maximumScore(vector<int>& nums, int k) 
    {
        LL n = nums.size();
        int MAX = *max_element(nums.begin(), nums.end());
        vector<int>s = Eratosthenes(MAX);
                        
        vector<LL>scores(n);
        for (int i=0; i<nums.size(); i++)
            scores[i] = s[nums[i]];
        
        vector<int>prevLarger(n, -1);
        stack<int>Stack;
        for (int i=0; i<n; i++)
        {
            while (!Stack.empty() &&  scores[Stack.top()] < scores[i])
                Stack.pop();
            if (!Stack.empty())
                prevLarger[i] = Stack.top();
            Stack.push(i);
        }
        
        vector<int>nextLarger(n, n);
        while (!Stack.empty()) Stack.pop();
        for (int i=n-1; i>=0; i--)
        {
            while (!Stack.empty() &&  scores[Stack.top()] <= scores[i])
                Stack.pop();
            if (!Stack.empty())
                nextLarger[i] = Stack.top();
            Stack.push(i);
        }
        
        vector<PII> temp(n);
        for (int i=0; i<nums.size(); i++)
        {            
            LL t = (LL)(i-prevLarger[i])*(nextLarger[i]-i);
            temp[i] = {nums[i], t};
        }
        
        sort(temp.rbegin(), temp.rend());
        
        LL ret = 1;
        for (auto [num, t]: temp)
        {
            if ((LL)k >= t)
            {
                ret = ret * quickMul(num, t) % M;
                k -= t;
            }
            else
            {
                ret = ret * quickMul(num, k) % M;
                k = 0;
            }
            if (k==0) break;
        }
        
        return ret;
    }
};
