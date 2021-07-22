using PII = pair<int,int>;
class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        int n = dominoes.size();
        vector<int>rets(n, -2);
        
        queue<PII>q;
        for (int i=0; i<n; i++)
        {
            if (dominoes[i]=='L')
            {
                q.push({i, -1});
                rets[i] = -1;
            }                
            else if (dominoes[i]=='R')
            {
                q.push({i, 1});            
                rets[i] = 1;
            }                
        }
                
        while (!q.empty())
        {
            int len = q.size();
            unordered_map<int,int>Map;
            while (len--)
            {
                auto [pos, dir] = q.front();
                q.pop();
                
                if (dir==1 && pos+1<n && rets[pos+1]==-2)
                    Map[pos+1] += 1;
                if (dir==-1 && pos-1>=0 && rets[pos-1]==-2)
                    Map[pos-1] -= 1;
            }
            for (auto x: Map)
            {
                q.push(x);
                rets[x.first] = x.second;
            }                
        }
        
        string ans;
        for (int i=0; i<n; i++)
        {
            if (rets[i]==1)
                ans.push_back('R');
            else if (rets[i]==-1)
                ans.push_back('L');
            else
                ans.push_back('.');
        }
        return ans;
    }
};
