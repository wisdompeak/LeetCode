using LL = long long;
using ULL = unsigned long long;
class Solution {
    ULL hashes[100001];
    ULL power[100001];
public:
    ULL getHash(string&s, int i, int len)
    {
        return hashes[i+len-1] - (i==0 ? 0 : hashes[i-1]*power[len]);
    }

    long long sumScores(string s) 
    {
        int n = s.size();        
        ULL hash = 0;
        for (int i=0; i<n; i++)
        {
            hash = hash*26 + (s[i]-'a');
            hashes[i] = hash;
        }

        power[0] = 1;
        for (int i=1; i<n; i++)
        {
            power[i] = power[i-1]*26;
        }

        LL ret = 0;
        for (int i=n-1; i>=0; i--)
        {
            if (s[i]!=s[0]) continue;
            int left = 1, right = n-i;
            while (left < right)
            {
                int mid = right - (right-left)/2;
                if (getHash(s, i, mid) != hashes[mid-1])
                    right = mid-1;
                else
                    left = mid;
            }
            ret += left;
        }

        return ret;        
    }
};
