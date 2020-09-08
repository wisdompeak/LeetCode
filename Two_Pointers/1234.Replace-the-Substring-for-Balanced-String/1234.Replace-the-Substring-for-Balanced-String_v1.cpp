class Solution {
    int n;
    unordered_map<char,int>Map;
    int count[4];
public:
    int balancedString(string s) 
    {
        n = s.size();        
        Map['Q'] = 0;
        Map['W'] = 1;
        Map['E'] = 2;
        Map['R'] = 3;        
        for (auto ch:s)
            count[Map[ch]] += 1;
        int flag = 1;
        for (int i=0; i<4; i++)
            if (count[i]!=n/4)
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
        vector<int>sum(4,0);
        for (int i=0; i<n; i++)
        {
            sum[Map[s[i]]]+=1;
            if (i>=k)
                sum[Map[s[i-k]]]-=1;

            int flag = 1;
            for (int c=0; c<4; c++)
                if (count[c]-sum[c] > n/4)
                {
                    flag  = 0;
                    break;
                }
            if (flag) return true;                    
        }
        return false;
    }
};
