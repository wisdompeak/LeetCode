using LL = long long;
class Solution {
    vector<pair<int,char>>next[100005];
    unordered_map<int, int>count;
    LL ret = 0;
public:
    long long countPalindromePaths(vector<int>& parent, string s) 
    {
        int n = parent.size();
        for (int i=1; i<n; i++)
        {
            next[parent[i]].push_back({i, s[i]});
        }

        int state = 0;
        dfs(0, -1, state);

        return ret;        
    }

    void dfs(int cur, int parent, int state)
    {
        if (count.find(state)!=count.end())
            ret += count[state];

        for (int i=0; i<26; i++)
        {
            int s = state ^ (1<<i);
            if (count.find(s)!=count.end())
                ret += count[s];
        }

        count[state] += 1;

        for (auto [nxt, ch]: next[cur])
        {
            if (nxt==parent) continue;
            dfs(nxt, cur, state^(1<<(ch-'a')));
        }
    }
};
