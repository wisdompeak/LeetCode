class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) 
    {
        unordered_map<int,unordered_set<int>>Map;
        unordered_map<int,unordered_set<int>>Children;
        for (int i=0; i<edges.size(); i++)
        {
            Map[edges[i][0]].insert(edges[i][1]);
            Map[edges[i][1]].insert(edges[i][0]);
        }
                        
        queue<int>q;
        q.push(0);
        while (!q.empty())
        {
            int root = q.front();            
            q.pop();
            for (auto child:Map[root])
            {
                Children[root].insert(child);    
                Map[child].erase(root);
                q.push(child);
            }                        
        }
        
        vector<int>SubLeaves(N);
        int root = 0;
        int temp = DFS1(root,Children,SubLeaves);
        
        int AllSum = DFS2(root,Children,SubLeaves);
        
        vector<int>results(N);
        results[0] = AllSum;
        DFS3(root,Children,SubLeaves,results);
        
        return results;
    }
    
    int DFS1(int x, unordered_map<int,unordered_set<int>>&Children, vector<int>&SubLeaves)
    {
        if (Children[x].size()==0)
        {
            SubLeaves[x]=1;
            return 1;
        }
        int sum = 1;
        for (auto a: Children[x])        
            sum+=DFS1(a,Children,SubLeaves);                    
        SubLeaves[x]=sum;   
        return sum;
    }
        
    int DFS2(int x, unordered_map<int,unordered_set<int>>&Children, vector<int>&SubLeaves)
    {
        if (Children[x].size()==0) return 0;        
        int sum = 0;
        for (auto a: Children[x])        
            sum+=DFS2(a,Children,SubLeaves)+SubLeaves[a];        
        return sum;
    }
    
    void DFS3(int x, unordered_map<int,unordered_set<int>>&Children, vector<int>&SubLeaves, vector<int>&results)
    {        
        for (auto a: Children[x])
        {
            results[a] = results[x] - SubLeaves[a] + results.size()-SubLeaves[a];
            DFS3(a,Children,SubLeaves,results);
        }
    }

};
