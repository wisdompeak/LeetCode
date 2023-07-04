class Solution {
    int memo[1005][26][26];
public:
    int minimizeConcatenatedLength(vector<string>& words) 
    {        
        return words[0].size() + dfs(1, words[0][0]-'a', words[0].back()-'a', words);        
    }
    
    // The minimum letters to be added if we construct the first i words with start & end.
    int dfs(int i, int start, int end, vector<string>& words) 
    {        
        if (i==words.size()) return 0;
        
        if (memo[i][start][end]!=0) return memo[i][start][end];
        
        int ret = INT_MAX/2;       
        int a = words[i][0]-'a', b = words[i].back()-'a';
        int len = words[i].size();

        if (end==a)
            ret = min(ret, len-1 + dfs(i+1, start, b, words));
        else
            ret = min(ret, len + dfs(i+1, start, b, words));

        if (start==b)
            ret = min(ret, len-1 + dfs(i+1, a, end, words));
        else
            ret = min(ret, len + dfs(i+1, a, end, words));
                            
        memo[i][start][end] = ret;
        return ret;
    }
};
