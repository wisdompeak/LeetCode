class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) 
    {
        if (blocked.size()<=1) return true;
        unordered_set<string>blocks;
        for (auto b:blocked)
            blocks.insert(to_string(b[0])+"#"+to_string(b[1]));
        
        if (enclose(source,target,blocks) || enclose(target,source,blocks))
            return false;
        else
            return true;
    }
    
    bool enclose(vector<int>& source, vector<int>& target, unordered_set<string>& blocks)
    {
        auto dir = vector<pair<int,int>>({{1,0},{-1,0},{0,1},{0,-1}});
        queue<pair<int,int>>q;
        unordered_set<string>visited;
        
        q.push({source[0],source[1]});
        visited.insert(to_string(source[0])+"#"+to_string(source[1]));
        
        while (!q.empty() && visited.size()<=19900)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for (int k=0; k<4; k++)
            {
                int i = x+dir[k].first;
                int j = y+dir[k].second;
                
                if (i<0||i>=1e6||j<0||j>=1e6)
                    continue;
                if (i==target[0] && j==target[1])
                    return false;
                
                string encode = to_string(i)+"#"+to_string(j);
                if (blocks.find(encode)!=blocks.end())
                    continue;
                if (visited.find(encode)!=visited.end())
                    continue;
                
                visited.insert(encode);
                q.push({i,j});
            }
        }
        
        if (q.empty()) 
            return true;
        else
            return false;
    }
};
