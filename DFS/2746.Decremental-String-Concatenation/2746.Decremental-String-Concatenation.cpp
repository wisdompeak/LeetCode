class Solution {
    int memo[1005][26][26];
public:
    int minimizeConcatenatedLength(vector<string>& words) 
    {
        return words[0].size() + dfs(1, words[0][0]-'a', words[0].back()-'a', words);        
    }

    // the minimum length to be added if we construct the first i words with start & end
    int dfs(int i, int start, int end, vector<string>& words)
    {
        if (i==words.size()) return 0;
        if (memo[i][start][end]!=0) return memo[i][start][end];

        int a = words[i][0]-'a', b = words[i].back()-'a';
        int len = words[i].size();
        int ret = INT_MAX/2;

        if (start==a && end==b)
        {
            // it does not matter we put words[i] at the beginning or at the end;
            ret = len - (a==b) + dfs(i+1, start, end, words);
        }
        else
        {
            // place words[i] at the end
            if (end==a)
                ret = min(ret, len-1 + dfs(i+1, start, b, words));
            else     
                ret = min(ret, len + dfs(i+1, start, b, words));

            // place words[i] at the beginning
            if (start==b)    
                ret = min(ret, len-1 + dfs(i+1, a, end, words));
            else    
                ret = min(ret, len + dfs(i+1, a, end, words));
        }

        memo[i][start][end] = ret;
        return ret;
    }
};
