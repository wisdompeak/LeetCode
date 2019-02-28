class Solution {
    int result = 0;
    unordered_map<int,vector<int>>Map;
public:
    int numSquarefulPerms(vector<int>& A) 
    {
        int N = A.size();
        sort(A.begin(),A.end());        
        for (int i=0; i<N; i++)
            for (int j=0; j<N; j++)
            {
                if (i==j) continue;
                if ((int)sqrt(A[i]+A[j])==sqrt(A[i]+A[j]))
                    Map[i].push_back(j);                
            }
        unordered_set<int>visited;
        for (int i=0; i<N; i++)
        {
            if (i>=1 && A[i]==A[i-1]) continue;
            visited.insert(i);
            DFS(A,visited,i);
            visited.erase(i);
        }        
        return result;        
    }
    
    void DFS(vector<int>&A, unordered_set<int>&visited, int cur)
    {
        if (visited.size()==A.size())
        {
            result++;
            return;
        }
        for (int i=0; i<Map[cur].size(); i++)
        {
            if (visited.find(Map[cur][i])!=visited.end()) continue;
            if (i>=1 && A[Map[cur][i]]==A[Map[cur][i-1]] && visited.find(Map[cur][i-1])==visited.end())
                continue;
            visited.insert(Map[cur][i]);
            DFS(A,visited,Map[cur][i]);
            visited.erase(Map[cur][i]);            
        }
    }
};
