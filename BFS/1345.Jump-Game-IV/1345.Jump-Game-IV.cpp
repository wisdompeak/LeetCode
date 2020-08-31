class Solution {    
public:
    int minJumps(vector<int>& arr) 
    {   
        unordered_map<int,vector<int>>Map;
        int n = arr.size();
        vector<int>ret(n,-1);
        
        for (int i=0; i<arr.size(); i++)
            Map[arr[i]].push_back(i);
        
        ret[0] = 0;
        queue<int>q;
        q.push(0);
        
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            if (cur>=1 && ret[cur-1]==-1)
            {
                ret[cur-1] = ret[cur]+1;
                q.push(cur-1);
            }
        
            if (cur<arr.size()-1 && ret[cur+1]==-1)
            {
                ret[cur+1] = ret[cur]+1;
                q.push(cur+1);
            }
            
            for (auto next: Map[arr[cur]])
            {
                if (ret[next]!=-1)
                    continue;
                ret[next] = ret[cur]+1;
                q.push(next);
            }
            Map.erase(arr[cur]);
        }
                        
        return ret[n-1];
    }    
};
