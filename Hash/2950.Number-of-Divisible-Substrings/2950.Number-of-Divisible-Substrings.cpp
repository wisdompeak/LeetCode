class Solution {
public:
    int countDivisibleSubstrings(string word) 
    {
        int n = word.size();
        word = "#"+word;
        vector<int>presum(n+1);
        for (int i=1; i<=n; i++)
            presum[i] = presum[i-1] + ((word[i]-'a'+1)/3+1);

        map<int, map<int,int>>Map;
        for (int m=1; m<=9; m++)
            Map[m][0] = 1;

        int ret = 0;
        for (int j=1; j<=n; j++)
        {
            for (int m = 1; m <=9; m++)
            {
                int key = presum[j] - m*j;
                if (Map.find(m)!=Map.end() && Map[m].find(key)!=Map[m].end())
                    ret += Map[m][key];
                Map[m][key]+=1;
            }
        }

        return ret;
    }
};
