class Solution
{
    int n;
    unordered_map<string,vector<string>>preMap;
    vector<vector<string>>results;

    public:
    vector<vector<string>> wordSquares(vector<string>& words)
    {
        n = words[0].size();
        for (string word:words)
            for (int i=0; i<n; i++)
                preMap[word.substr(0,i)].push_back(word);
        vector<string>square(n);
        build(square,0);
        return results;
    }

    void build(vector<string>&square, int k)
    {
        if (k==n)
        {
            results.push_back(square);
            return;
        }

        string prefix;
        for (int i=0; i<k; i++)
            prefix+= square[i][k];
        for (string nextWord: preMap[prefix])
        {
            square[k] = nextWord;
//            for (int i=0; i<n; i++)
//                square[i][k] = nextWord[i];
            build(square,k+1);
        }
    }
};
