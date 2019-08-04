class Solution {
public:
    int minimumSemesters(int N, vector<vector<int>>& relations) 
    {
        unordered_map<int,unordered_set<int>>In;
        unordered_map<int,unordered_set<int>>Out;
        for (auto x:relations)
        {
            Out[x[0]].insert(x[1]);
            In[x[1]].insert(x[0]);
        }
        
        queue<int>q;
        unordered_set<int>visited;
        for (int i=1; i<=N; i++)
        {
            if (Out[i].size()==0)
            {
                q.push(i);
                visited.insert(i);
            }
                
        }
        
        int step = 0;
        while (!q.empty())
        {
            step++;
            int len = q.size();
            for (int i=0; i<len; i++)
            {
                int cur = q.front();
                for (auto pre: In[cur])
                    Out[pre].erase(cur);
                q.pop();
            }
            vector<int>list;
            for (int i=1; i<=N; i++)
            {
                if (visited.find(i)!=visited.end())
                    continue;
                if (Out[i].size()==0)
                {
                    list.push_back(i);
                    visited.insert(i);
                }                    
            }
                        
            if (list.size()==0 && visited.size()!=N)
                return -1;
                
            for (auto x:list)
                q.push(x);
        }
        
        if (visited.size()!=N)
            return -1;
        else
            return step;
    }
};
