class Solution {
    int n;
    unordered_map<char,int>count;
public:
    int balancedString(string s) 
    {
        n = s.size();        
        for (auto ch:s)
            count[ch] += 1;
        int flag = 1;
        for (auto x: count)
            if (x.second!=n/4)
                flag = 0;
        if (flag==1) return 0;

        int left = 1, right = n;
        while (left<right)
        {
            int mid = left+(right-left)/2;
            if (isOK(mid, s))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }

    bool isOK(int k, string& s)
    {
        unordered_map<char,int>sum;
        for (int i=0; i<n; i++)
        {
            sum[s[i]]+=1;
            if (i>=k)
                sum[s[i-k]]-=1;

            int flag = 1;
            for (auto x: count)
            {
                char ch = x.first;
                if (count[ch]-sum[ch] > n/4)
                {
                    flag  = 0;
                    break;
                }
            }
            if (flag) return true;                    
        }
        return false;
    }
};
