class Solution {
public:
    int countVowelStrings(int n) 
    {
        return help(n+4,4);
    }

    int help(int n, int m)
    {
        long long cnt = 1;
        for(int i = 0; i < m; i++)
        {
            cnt *= n - i;
            cnt /= i + 1;
        }
        return cnt;
    }
};
