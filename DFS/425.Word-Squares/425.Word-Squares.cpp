class Solution {
    vector<vector<string>>rets;
    unordered_map<string, vector<string>>Map;
    int n;
public:
    vector<vector<string>> wordSquares(vector<string>& words) 
    {
        this->n = words[0].size();
        for (auto& word: words)
        {
            for (int i=0; i<n; i++)
                Map[word.substr(0, i)].push_back(word);
        }
        vector<string>ret;
        dfs(0, ret, words);
        return rets;
    }
    
    void dfs(int row, vector<string>&ret, vector<string>& words)
    {
        if (row==n)
        {    
            rets.push_back(ret);
            return;
        }
        
        string prefix;
        for (int i=0; i<row; i++)
            prefix.push_back(ret[i][row]);
        
        for (auto& word: Map[prefix])
        {
            ret.push_back(word);                                
            dfs(row+1, ret, words);
            ret.pop_back();                
        }
    }
};
