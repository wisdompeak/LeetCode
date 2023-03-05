class Solution {
    vector<int> next[100005];
    unordered_set<int> guess[100005];
    int k;
    int ret = 0;
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        this->k = k;
        int n = edges.size()+1;
        for (auto& e: edges)
        {
            next[e[0]].push_back(e[1]);
            next[e[1]].push_back(e[0]);
        }
        for (auto& g: guesses)
            guess[g[0]].insert(g[1]);

        int count = dfs(0, -1);

        dfs2(0, -1, count);

        return ret;
    }

    int dfs(int cur, int parent)
    {
        int count = 0;
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;
            count += dfs(nxt, cur);
            if (guess[cur].find(nxt)!=guess[cur].end())
                count +=1;
        }
        return count;
    }

    void dfs2(int cur, int parent, int count)
    {
        if (count >= k) ret++;
        for (int nxt: next[cur])
        {
            if (nxt==parent) continue;
            int temp = count;
            if (guess[cur].find(nxt)!=guess[cur].end())
                temp -= 1;
            if (guess[nxt].find(cur)!=guess[nxt].end())
                temp += 1;
            dfs2(nxt, cur, temp);
        }
    }
};
