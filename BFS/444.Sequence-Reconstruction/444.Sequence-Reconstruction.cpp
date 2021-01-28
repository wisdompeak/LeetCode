class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) 
    {
        if (seqs.size() == 0)
            return false;
        int n = org.size();
        vector<int>indegree(n+1);
        vector<vector<int>>out(n+1);
        
        for (auto seq: seqs)
            for (int i: seq)
                if (i>n || i<1) return false;
        
        for (auto seq: seqs)
        {            
            for (int i=1; i<seq.size(); i++)
            {                
                out[seq[i-1]].push_back(seq[i]);
                indegree[seq[i]]++;
            }                
        }
        
        queue<int>q;
        for (int i=1; i<=n; i++)
        {
            if (indegree[i]==0)
                q.push(i);
        }
        
        int i = 0;
        while (!q.empty())
        {
            if (q.size()>1)
                return false;
            
            int x = q.front();            
            q.pop();
            if (x!=org[i]) return false;
            i++;
            
            for (int next: out[x])
            {
                indegree[next]--;
                if (indegree[next]==0)
                    q.push(next);
            }
        }
        
        if (i!=org.size()) return false;
        
        return true;        
    }
};
